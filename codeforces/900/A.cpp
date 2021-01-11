#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,o=0,s=0;
    cin >> n;
    for(int i =0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(x > 0 && y >= 0 || x > 0 && y<=0)o++;
        else if(x < 0 && y <= 0 || y >= 0 && x<0)s++;
    }
    if(o <= 1 || s<= 1)cout << "YES";
    else cout << "NO";
}