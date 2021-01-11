#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,idx,minimum=1000000000;
    string m;
    cin >> n >> m;
    int p[n];
    for(int i = 0;i<n;i++){
        cin >> p[i];
        int diff=(p[i]-p[i-1])/2;
        if(diff < minimum && m[i-1] == 'R' && m[i] == 'L')minimum=diff;
    }
    
    if(minimum != 1000000000)cout << minimum;
    else cout << -1;
}