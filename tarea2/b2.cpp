// https://vjudge.net/contest/552674#problem/B
#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> parent;

void bfs(int s, int n, vector<vector <int>> grafo){
    dist.assign(n, -1);
    parent.assign(n, -1);
    queue<int> Cola;
    dist[s] = 0;
    Cola.push(s);
    while(!Cola.empty()){
        int u = Cola.front(); Cola.pop();
        for(int v:grafo[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                parent[v] = u;
                Cola.push(v);
            }
        }
    }
}

int main(){
    int n, m, a, b, d, p;
    cin>>n>>m;
    vector<vector <int>> grafo(n);
    while(m--){
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    bfs(0, n, grafo);
    d = dist[n-1]+1; p = n-1;
    if(!d){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    } else cout<<d<<endl;
    vector<int> path(d);
    for(int i=0; i<d; i++){
        path[d-i-1]=p;
        p = parent[p];
    }
    for(int n:path) cout<<n+1<<" ";
    return 0;
}