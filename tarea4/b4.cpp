#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int n; cin>>n;
    int cnt = 0;
    while(n--){
        ll a, b, c; cin>>a>>b>>c;
        ll dis1 = (a*x1)+(b*y1)+c;
        ll dis2 = (a*x2)+(b*y2)+c;
        if(dis1<0 != dis2<0) cnt++;
    }
    cout<<cnt<<endl;
}