#include <bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    point(double x=0, double y=0): x(x), y(y){}
    bool leftOf(point A, point B) {return ((B.x - A.x)*(this -> y - A.y) - (B.y - A.y)*(this -> x - A.x)) > 0;}
};

int main(){
    
}