#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int a,b,ans = 0,x=0;
    cin >> a >> b;
    ans += a;
    x = a;
    while(x / b > 0){
        ans += x / b;
        x = x/b + x%b;
    }
    cout << ans;
}