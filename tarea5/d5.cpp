#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int linearSum(int n){
    return (n * (n + 1) / 2) % 1000000007;
}

int rangeSum(int b, int a){
    return (linearSum(b) - linearSum(a)) % 1000000007;
}

int main(){
    ll n, sum=0, i=1; cin>>n;
    while(1){
        sum += rangeSum(n / i, n / (i + 1)) * (i % 1000000007) % 1000000007;
        sum %= 1000000007;
        if(i==n) break;
        i = n/(n/(i+1));
    }
    cout<<sum<<endl;
    return 0;
}