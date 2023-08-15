// https://vjudge.net/contest/559143#problem/C
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector <vector <ll>> grafo(n);
        while(m--){
            int a, b; cin>>a>>b;
            grafo[a-1].push_back(b-1);
            grafo[b-1].push_back(a-1);
        }
        ll x, y;
        for(int i=0; i<n; i++){
            if(grafo[i].size()==1){
                vector <ll> node = grafo[grafo[i][0]];
                y = node.size();
                for(auto j:node){
                    if(grafo[j].size()-1){
                        x = grafo[j].size();
                        break;
                    }
                }
                break;
            }
        }
        cout<<x<<" "<<--y<<endl;
    }
}