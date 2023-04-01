#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m=0;
    cin>>n;
    queue<long long> flies;
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        flies.push(a);
    }
    
    cout<<m<<endl;
    return 0;
}