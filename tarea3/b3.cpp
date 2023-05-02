#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 1e18;

int main(){
	int n, m; cin >> n >> m;
	using state = pair<ll,int>;
	vector <vector <state>> adj(n); 
	for(int i=0; i<m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	priority_queue <state, vector<state>, greater<state>> pq;
	vector <ll> dist(n, INF), parent(n);
	for(int i=0; i<n; i++) parent[i] = i;
	pq.push({0,0});
	dist[0] = 0;
	while(!pq.empty()){
		auto [peso_camino, u] = pq.top();
		pq.pop();
		if(peso_camino != dist[u]) continue;
		for(auto [v, w] : adj[u]){
			if(peso_camino+w < dist[v]){
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
                parent[v] = u;
			}
		}
	}
	if(dist[n-1] == INF){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> path;
	int node = n-1;
	while(parent[node]!=node){
		path.push_back(node+1);
		node = parent[node];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	for(int it:path) cout<<it<<" ";
	return 0;
}