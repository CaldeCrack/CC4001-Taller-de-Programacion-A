#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,int>;
ll INF = 1e18;
vector <ll> parent;

ll nearShortPath(vector <vector <state>>& adj, int n, int s, int m){
	priority_queue <state, vector<state>, greater<state>> pq;
	vector <ll> dist(n, INF);
	for(int i=0; i<n; i++) parent[i] = i;
	pq.push({0,0});
	dist[0] = 0;
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
}

int main(){
	int n=2;
	while(n>1){
		int m, s, d; cin >> n >> m >> s >> d;
		vector <vector <state>> adj(n); 
		for(int i=0; i<m; i++){
			int u, v;
			ll w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
		}
		ll currDist = nearShortPath(adj, n, s, m);
		ll shortDist = currDist;
		if(shortDist==INF){
			cout<<-1<<endl;
			return 0;
		}
		while(currDist==shortDist) currDist = nearShortPath(adj, n, s, m);
		if(shortDist==INF){
			cout<<-1<<endl;
			return 0;
		}
		cout<<currDist<<endl;
	}
	return 0;
}