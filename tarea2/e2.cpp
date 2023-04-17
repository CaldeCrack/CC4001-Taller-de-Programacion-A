#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> rep;
map<int, int> len;

void dfs(int s, vector<vector<int>> &grafo, vector<int> &visited){
    stack<int> pila;
    pila.push(s);
    len[s]=1; rep[s]=s;
    while(!pila.empty()){
        int u=pila.top();
        pila.pop();
        visited[u]=1;
        for(int v:grafo[u]){
            if(visited[v]==-1){
                visited[v]=1;
                len[s]++;
                rep[v]=s;
                pila.push(v);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grafo(n);
    vector<int> visited(n, -1);
    rep.assign(n, -1);
    while(m--){
        int k;
        cin>>k;
        if(!k) continue;
        int p;
        cin>>p;
        p--;
        k--;
        while(k--){
            int u;
            cin>>u;
            u--;
            grafo[p].push_back(u);
            grafo[u].push_back(p);
        }
    }
    for(int i=0; i<n; i++){
        if(visited[i]==-1) dfs(i, grafo, visited);
        cout<<len[rep[i]]<<' ';
    }
}