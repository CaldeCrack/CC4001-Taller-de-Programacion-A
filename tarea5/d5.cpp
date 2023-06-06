#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, sum=0; cin>>n;
    for(ll i=1; i<=sqrt(n); i++) sum+=(n/i-i+1)*i+(((n/i)*(n/i+1))/2)-((i*(i+1))/2);
    cout<<sum%1000000007<<endl;
    return 0;
}