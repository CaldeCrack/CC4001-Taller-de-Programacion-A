#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<vector<int>> &grafo, vector<int> &visited){
    visited[s]=1;
    for(int v:grafo[s]) if(!visited[v]) dfs(v, grafo, visited);
}

int main(){
    int n, d=0;
    cin>>n;
    map<int, vector<int>> grafo(2*n);
    map<int> visited(2*n, 0);
    while(n--){
        int x, y;
        cin>>x>>y;

    }
    for(int i=0; i<n; i++){

    }
}