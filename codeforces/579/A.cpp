#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,ans=1;
    cin >> x;
    while(x!=1){
        if(x & 1)ans++;
        x = x >> 1;
    }
    cout << ans;
}