#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    ll t;
    cin >> t;

    while(t--){
        ll a,b,k;
        cin >> a >> b >> k;
        ll ans = (k/2) * (a-b);
        if(k % 2) ans += a;
        cout << ans << '\n';
    }
}