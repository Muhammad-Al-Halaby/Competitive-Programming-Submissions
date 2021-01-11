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
    ll n,m,currX,currY,k;
    ll ans = 0;
    cin >> n >> m >> currX >> currY >> k;
    for(int i = 0;i < k;i++){
        ll dx,dy;
        cin >> dx >> dy;
        ll l = 0, r = 1e9+10;
        while(l < r){
            ll mid = (l + r + 1) >> 1;
            if(mid * dx + currX > 0 && mid * dx + currX <= n &&  mid * dy + currY > 0 && mid * dy + currY <= m)
                l = mid;
            else
                r = mid - 1;
        }
        if(l * dx + currX > 0 && l * dx + currX <= n && l * dy + currY > 0 && l * dy + currY <= m){
            ans += l;
            currX += l * dx;
            currY += l * dy;
        }
    }
    cout << ans;
}