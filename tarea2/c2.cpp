#include <bits/stdc++.h>
using namespace std;

void dfs(int s, map<int, vector<int>> &grafo, map<int, int> &visited){
    visited[s]=1;
    for(int v:grafo[s]) if(!visited[v]) dfs(v, grafo, visited);
}

int main(){
    int n, x2, d=0;
    cin>>n;
    map<int, vector<int>> grafo;
    map<int, int> visited;
    while(n--){
        int x, y;
        cin>>x>>y;
        grafo[x].push_back(y+1000);
        grafo[y+1000].push_back(x);
        x2=x;
    }
    dfs(x2, grafo, visited);
    for (auto i = grafo.begin(); i != grafo.end(); i++) {
        if(!visited[i->first]){
            dfs(i->first, grafo, visited);
            d++;
        }
    }
    cout<<d<<endl;
    return 0;
}