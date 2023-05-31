#include <bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    point(double x=0, double y=0): x(x), y(y){}
    bool leftOf(point A, point B) {return ((B.x - A.x)*(this -> y - A.y) - (B.y - A.y)*(this -> x - A.x)) > 0;}
};

int main(){
    double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int n; cin>>n;
    int cnt = 0;
    point house = {x1, y1};
    point fcgm = {x2, y2};
    while(n--){
        double a, b, c; cin>>a>>b>>c;
        if(a == 0){
            if((-c/b - house.y)*(-c/b - fcgm.y) < 0) cnt++;
        }
        else if(b == 0){
            if((-c/a - house.x)*(-c/a - fcgm.x) < 0) cnt++;
        }
        else{
            point p1 = {-c/a, 0};
            point p2 = {0, -c/b};
            if(house.leftOf(p1, p2) != fcgm.leftOf(p1,p2)) cnt++;
        }
    }
    cout<<cnt<<endl;
}