#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ll n, m=0, i=0;
    cin>>n;
    map<ll, ll> occurrence;
    for (ll j = 0; j < n; j++) {
        ll a;
        cin>>a;
        i = max(i, occurrence[a-1]);
        m = max(m, j - i + 1);
        occurrence[a-1] = j+1;
    }
    cout<<m<<endl;
    return 0;
}