#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,ll>;
ll INF = 1e18;

void dijkstra(int s, vector<vector<state>> &adj, vector<ll> &dist){
	dist[s] = 0;
	priority_queue<state, vector<state>, greater<state>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		auto [peso, u] = pq.top();
		pq.pop();
		if(peso != dist[u]) continue;
		for(auto [v, w]:adj[u]){
			if(peso+w < dist[v]){
				dist[v] = peso+w;
				pq.push({dist[v], v});
			}
		}
	}
}

void minCostPath(vector<vector<state>> &adjI, vector<vector<state>> &adjD, int n, int m){
	vector<ll> dist_from_s(n+1, INF);
	vector<ll> dist_from_d(n+1, INF);
	dijkstra(1, adjI, dist_from_s);
	dijkstra(n, adjD, dist_from_d);
	ll min_cost = dist_from_s[n];
	for(int i=0; i<adjI.size(); i++){
        for(auto [v,c]:adjI[i]){
			min_cost = min(min_cost, dist_from_s[i]+c/2+dist_from_d[v]);
		}
	}
	cout<<min_cost<<endl;
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<state>> adjI(n+1);
	vector<vector<state>> adjD(n+1);
	for(int i=0; i<m; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		adjI[a].push_back({b,c});
		adjD[b].push_back({a,c});
	}
	minCostPath(adjI, adjD, n, m);
	return 0;
}