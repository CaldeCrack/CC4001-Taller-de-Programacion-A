#include<bits/stdc++.h>
using namespace std;

long long int ceildiv(long long int a, long long int b){
    return 1+((a-1)/b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        bool ok = false;
        for (int i=0; i<=k; i++){
            long long int tp = ceildiv(hm,dc+(k-i)*w);
            long long int tm = ceildiv(hc+i*a,dm);
            if (tp<=tm){
                ok=true;
                cout<<"YES"<<endl;
                break;
            }
        }
        if (!ok) cout<<"NO"<<endl;
    }
    return 0;
}