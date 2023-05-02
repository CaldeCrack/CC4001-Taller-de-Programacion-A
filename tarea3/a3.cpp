#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,ll>;
ll INF = 1e18;

void dijkstra(int s, int n, vector<state> adj[], vector<ll> &dist){
	priority_queue <state, vector<state>, greater<state>> pq;
	dist.assign(n, INF);
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [peso_camino, u] = pq.top();
		pq.pop();
		if(peso_camino != dist[u]) continue; //! maybe quitar
		for (auto [v, w] : adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
}

void minCostPath(vector<pair<ll,state>> &edges, int n, int m){
	vector<state> adj[100005];
	for(int i=0; i<m; i++){
		ll x = edges[i].first;
		auto [y, z] = edges[i].second;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	vector<ll> dist_from_source;
	vector<ll> dist_from_dest;
	dijkstra(0, n, adj, dist_from_source);
	dijkstra(n, n, adj, dist_from_dest);
	ll min_cost = dist_from_source[n];
	for (auto &it:edges) {
		ll u = it.first;
		auto [v, c] = it.second;
		ll cur_cost = dist_from_source[u]+c/2+dist_from_dest[v];
		min_cost = min(min_cost, cur_cost);
	}
	cout << min_cost << '\n';
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<pair<ll,state>> edges;
	for(int i=0; i<m; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		a--;
		b--;
		edges.push_back({a, {b,c}});
	}
	minCostPath(edges, n, m);
	return 0;
}