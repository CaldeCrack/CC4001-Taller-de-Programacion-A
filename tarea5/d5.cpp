#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod=1000000007;

int sum(ll m){
    return (m*(m+1)/2)%mod;
}

int main(){
    ll n, res=0, i=1; cin>>n;
    while(1){
        res += ((sum(n/i)-sum(n/(i+1)))%mod)*(i%mod)%mod;
        res %= mod;
        if(i==n) break;
        i = n/(n/(i+1));
    }
    cout<<res<<endl;
    return 0;
}