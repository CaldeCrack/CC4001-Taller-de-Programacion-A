#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cnt=0, n, x, y;
    map<long long, int> wx;
    map<long long, int> wy;
    pair<long long, long long> p;
    map<pair <long long, long long>, int> c;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        cnt+=wx[x]++;
        cnt+=wy[y]++;
        p.first = x, p.second = y;
        cnt-=c[p]++;
    }
    cout<<cnt<<endl;
    return 0;
}