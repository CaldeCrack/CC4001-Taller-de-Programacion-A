// https://vjudge.net/contest/560153#problem/A
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n; m=n; n<<=1;
        double sum=0;
        priority_queue<double> diamonds;
        priority_queue<double> miners;
        while(n--){
            int x, y;
            cin>>x>>y;
            if(x) diamonds.push(abs(x));
            else miners.push(abs(y));
        }
        while(m--){
            sum += sqrt(pow(diamonds.top(), 2)+pow(miners.top(), 2));
            diamonds.pop(); miners.pop();
        }
        cout<<fixed<<setprecision(10)<<sum<<endl;
    }
}