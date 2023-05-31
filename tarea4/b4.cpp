#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point{
    float x,y;
    point(float x=0, float y=0): x(x), y(y){}
    point operator -(point o){
        return x-o.x, y-o.y;
    }
    double operator ^(point o){
        return x*o.y-y*o.x;
    }
    bool leftOf(point A, point B){
        return ((B-A)^((*this)-A)) > 0;
    }
};

int main(){
    float x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int n; cin>>n;
    int cnt = 0;
    point house = {x1, y1};
    point fcgm = {x2, y2};
    while(n--){
        float a, b, c; cin>>a>>b>>c;
        if(a == 0){
            if((-c/b - house.y)*(-c/b - fcgm.y) < 0){
                cnt++;
                continue;
            }
        }
        else if(b == 0){
            if((-c/a - house.x)*(-c/a - fcgm.x) < 0){
                cnt++;
                continue;
            }
        }
        else{
            point p1 = {-c/a, 0};
            point p2 = {0, -c/b};
            if(house.leftOf(p1, p2) != fcgm.leftOf(p1,p2)){
                cnt++;
                continue;
            }
        }
    }
    cout<<cnt<<endl;
}