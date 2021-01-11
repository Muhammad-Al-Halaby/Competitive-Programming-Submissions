#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    
    ll n,ans=0;
    cin >> n;
    
    for(ll i = 9;n > 0;i*=10){
        ans += n;
        n -= i;
    }
    
    cout << ans;
}