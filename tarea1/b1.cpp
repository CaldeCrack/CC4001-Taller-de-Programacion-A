#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m=0;
    cin>>n;
    vector<long long> flies(n);
    for(long long i = 0; i < n; i++){ // create vector with flies
        long long a;
        cin>>a;
        flies[i]=a;
    }
    for(long long i = 0; i < n; i++){
        set<long long> max_flies;
        long long s;
        for(long long j = 0; j < n; j++){
            s = max_flies.size();
            max_flies.insert(flies[j]);
            if(s==max_flies.size()){
                if(m<s) m==s;
                break; //alo
            }
        }
    }
    cout<<m<<endl;
    return 0;
}