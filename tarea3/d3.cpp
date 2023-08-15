// https://vjudge.net/contest/555021#problem/D
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using state = pair<ll,ll>;
ll inf = 1e18;

vector<vector<int>> graph;
vector<vector<int>> paths;
vector<int> vi;

int adjm[501][501];
int n, m, s, d;

void dijkstra(){
    set<state> ordered;
    ordered.insert({0, s});
    vector <ll> dist(n, inf);
    dist[s] = 0;
    int node, cost;
    while(!ordered.empty()){
        cost = (*ordered.begin()).first;
        node = (*ordered.begin()).second;
        ordered.erase(ordered.begin());
        for(int i = 0; i < graph[node].size(); i++){
            int newn = graph[node][i], newc = adjm[node][newn];
            if(cost + newc <= dist[newn]){
                if(cost + newc < dist[newn]) paths[newn].clear();
                paths[newn].push_back(node);
                if(dist[newn] != inf) ordered.erase({dist[newn], newn});
                dist[newn] = cost + newc;
                ordered.insert({dist[newn], newn});
            }
        }
    }
}

void removeEdges(int node){
    for(int i=0; i<paths[node].size(); i++){
        int neigh = paths[node][i];
        adjm[neigh][node] = -1;
        removeEdges(neigh);
    }
}

int dijkstra2(){
    set <state> ordered;
    ordered.insert({0, s});
    vector<ll> dist(n, inf);
    dist[s] = 0;
    int node, cost;
    while(!ordered.empty()){
        cost = (*ordered.begin()).first;
        node = (*ordered.begin()).second;
        if(node == d)return cost;
        ordered.erase(ordered.begin());
        for(int i=0; i<graph[node].size(); i++){
            int newn = graph[node][i], newc = adjm[node][newn];
            if(newc == -1) continue;
            if(cost+newc < dist[newn]){
                if (dist[newn] != inf)ordered.erase({dist[newn], newn});
                dist[newn] = cost + newc;
                ordered.insert({dist[newn], newn});
            }
        }
    }
    return -1;
}

int main(){
    while (1){
        cin>>n>>m;
        if(n<2) return 0;
        cin>>s>>d;
        graph.insert(graph.begin(), n, vi);
        paths.insert(paths.begin(), n, vi);
        for(int i=0; i<m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            graph[u].push_back(v);
            adjm[u][v] = w;
        }
        dijkstra();
        removeEdges(d);
        cout<<dijkstra2()<<endl;
        graph.clear();
        paths.clear();
    }
    return 0;
}