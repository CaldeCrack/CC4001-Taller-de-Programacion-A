#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum(int n){
    return (n*(n+1)/2)%1000000007;
}

int main(){
    ll n, res=0, i=1; cin>>n;
    while(1){
        res += ((sum(n/i)-sum(n/(i+1)))%1000000007)*(i%1000000007)%1000000007;
        res %= 1000000007;
        if(i==n) break;
        i = n/(n/(i+1));
    }
    cout<<res<<endl;
    return 0;
}