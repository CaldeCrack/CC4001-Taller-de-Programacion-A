#include<iostream>
#include<algorithm>
using namespace std;

int t, n, m;
string f, s;

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        int c=0;
        cin >> n >> m;
        cin >> f >> s;
        reverse(s.begin(), s.end());
        f+=s;
        for (int j = 0; j < n+m-1; j++){
            if (f[j] == f[j+1]) c++;
        }
        if (c < 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}