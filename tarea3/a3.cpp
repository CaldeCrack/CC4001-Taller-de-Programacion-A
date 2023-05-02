#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<int,int>;
ll INF = 1e18;

void dijkstra(int s, int n, vector<state> adj[], vector<ll> &dist){
	dist.assign(n, INF);
	dist[s] = 0;
	priority_queue<state, vector<state>,greater<state>> pq;
	pq.push({dist[s], s});
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto &edge:adj[u]){
			int v = edge.first;
			int w = edge.second;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});
			}
		}
	}
}

void minCostPath(vector<pair<int, state>> &edges, int n, int m){
	vector<state> adj[100005];
	for(int i=0; i<m; i++){
		int x = edges[i].first;
        auto [y, z] = edges[i].second;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	vector<ll> dist_from_s;
	vector<ll> dist_from_d;
	dijkstra(1, n+1, adj, dist_from_s);
	dijkstra(n, n+1, adj, dist_from_d);
	ll min_cost = dist_from_s[n];
	for(auto &it:edges){
		int u = it.first;
        auto [v,c] = it.second;
		ll cur_cost = dist_from_s[u]+c/2+dist_from_d[v]; // agradecido maximo
		min_cost = min(min_cost, cur_cost);
	}
	cout<<min_cost<<endl;
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<pair<int, state>> edges;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({a, {b,c}});
	}
	minCostPath(edges, n, m);
	return 0;
}