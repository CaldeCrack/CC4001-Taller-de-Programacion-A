#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    while(cin>>n){
        stack<int> s; queue<int> q; priority_queue<int> pq;
        int isS=1, isQ=1, isPQ=1;
        for(int i = 0; i < n; i++){
            int op, v;
            cin>>op>>v;
            if(op==1){
                s.push(v); q.push(v); pq.push(v);
            } else {
                if(s.empty() or s.top()!=v) isS=0;
                else s.pop();
                if(q.empty() or q.front()!=v) isQ=0;
                else q.pop();
                if(pq.empty() or pq.top()!=v) isPQ=0;
                else pq.pop();
            }
        }
        if(!(isS+isQ+isPQ)) cout<<"impossible"<<endl;
        else if(isS+isQ+isPQ>1) cout<<"not sure"<<endl;
        else{
            if(isS) cout<<"stack"<<endl;
            else if(isQ) cout<<"queue"<<endl;
            else cout<<"priority queue"<<endl;
        }
    }
    return 0;
}