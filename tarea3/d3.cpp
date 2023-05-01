#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,int>;
ll INF = 1e18;

ll nearShortPath(vector <vector <state>>& adj, int n, int s, int d){
	// Dijkstra Algorithm
	priority_queue <state, vector<state>, greater<state>> pq;
	vector <ll> dist(n, INF), parent(n);
	for(int i=0; i<n; i++) parent[i] = i;
	pq.push({s,0});
	dist[s] = 0;
	while(!pq.empty()){
		auto [peso_camino, u] = pq.top();
		pq.pop();
		if(peso_camino != dist[u]) continue;
		for(auto [v, w] : adj[u]){
			if(peso_camino + w < dist[v]){
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
                parent[v] = u;
			}
		}
	}
	if(dist[d] == INF) return INF;
	// Remove edges in shortest path (change its weight to INF)
    vector<int> path;
	int node = d;
	while(parent[node]!=node){
		path.push_back(node);
		node = parent[node];
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	for(int it:path){
		for(auto [v, w] : adj[it]){
			if(v==path[it+1]){
				w = INF;
				break;
			}
		}
	}
	return dist[d];
}

int main(){
	int n=2;
	while(n>1){
		// Adjacency list
		int m, s, d; cin >> n >> m >> s >> d;
		if(n<2) return 0;
		vector <vector <state>> adj(n); 
		for(int i=0; i<m; i++){
			int u, v;
			ll w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
		}
		// Near Shortest Path
		ll currDist = nearShortPath(adj, n, s, d);
		if(currDist==INF){
			cout<<-1<<endl;
			return 0;
		}
		ll shortDist = currDist;
		while(currDist==shortDist) currDist = nearShortPath(adj, n, s, d);
		if(currDist==INF){
			cout<<-1<<endl;
			return 0;
		}
		cout<<currDist<<endl;
	}
	return 0;
}