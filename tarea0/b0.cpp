// https://vjudge.net/contest/547505#problem/B
#include <iostream>
using namespace std;

int n, h, i, extra=0;

int main()
{
    cin >> n;
    cin >> h;
    for (int k = 0; k < n; k++){
        cin >> i;
        if(i>h){
            extra++;
        }
    }
    cout << n+extra << endl;
    return 0;
}