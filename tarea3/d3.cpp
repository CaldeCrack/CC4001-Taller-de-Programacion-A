#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,ll>;
ll INF = 1e18;

void fillSet(set<ll> &shortNodes, vector<vector<state>> parents, int s, int d, ll bd){
	for(auto i:parents[d]){
		if(i.first==s || i.second > bd) continue;
		shortNodes.insert(i.first);
		fillSet(shortNodes, parents, s, i.first, bd);
	}
	return;
}

ll nearShortPath(vector <vector <state>> &adj, int n, int s, int d){
	// Dijkstra Algorithm
	// cout<<"adyacencia: "<<adj[0][3].second<<endl;
	priority_queue <state, vector<state>, greater<state>> pq;
	vector<vector<state>> parents(n);
	vector<ll> dist(n, INF);
	set<ll> shortNodes;
	ll bestDistance, minDistance = INF;
	pq.push({0,s});
	dist[s] = 0;
	while(!pq.empty()){
		auto [path_weight, u] = pq.top();
		pq.pop();
		if(path_weight != dist[u]) continue;
		for(auto [v, w] : adj[u]){
			if(path_weight + w <= dist[v] && w != INF){
				// cout<<"nodo / peso: "<<v<<" "<<w<<endl;
				dist[v] = path_weight+w;
				pq.push({dist[v], v});
                parents[v].push_back({u, path_weight+w});
			}
		}
	}
	bestDistance = dist[d];
	shortNodes.insert(d);
	fillSet(shortNodes, parents, s, d, bestDistance);
	cout<<"padres de d:"<<endl; for(auto i:parents[d]) cout<<i.first<<" "<<i.second<<endl;
	cout<<"nodos en shortNodes: "; for(auto i:shortNodes) cout<<i<<" "; cout<<endl;
	cout<<"distancias: "; for(auto i:dist) cout<<i<<" "; cout<<endl;
	if(dist[d] == INF) return INF; //! mover arriba probablemente
	// Remove edges in shortest path (change its weight to INF)
	for(auto i:shortNodes){
		for(auto j:parents[i]){
			for(int k=0; k<adj[j.first].size(); k++){
				minDistance = min(minDistance, adj[j.first][k].second);
			}
			cout<<"bestDistance: "<<bestDistance<<endl;
			for(int k=0; k<adj[j.first].size(); k++){
				cout<<"nodo adj: "<<adj[j.first][k].first<<" "<<adj[j.first][k].second<<endl;
				cout<<"nodo: "<<j.first<<" "<<j.second<<endl;
				if(adj[j.first][k].first==i && adj[j.first][k].second == minDistance && j.second <= bestDistance){
					cout<<"infinito"<<endl;
					adj[j.first][k].second = INF;
					continue;
				}
			}
		}
		minDistance = INF;
	}
	return dist[d];
}

int main(){
	while(1){
		// Adjacency list
		int n, m; cin >> n >> m;
		if(n<2) break;
		int s, d; cin >> s >> d;
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
			continue;
		}
		ll shortDist = currDist;
		// cout<<currDist<<endl;
		// while(currDist==shortDist) currDist = nearShortPath(adj, n, s, d);
		currDist = nearShortPath(adj, n, s, d);
		if(currDist==INF){
			cout<<-1<<endl;
			continue;
		}
		cout<<currDist<<endl;
	}
	return 0;
}