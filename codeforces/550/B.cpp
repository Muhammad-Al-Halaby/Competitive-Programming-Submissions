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
    int n,l,r,x;
    ll ans = 0;
    cin >> n >> l >> r >> x;
    int c[n];
    for(int i = 0;i < n;i++)
        cin >> c[i];
    for(int i = 0;i<(1 << n);i++){
        int mx=0,mn=2e6,total = 0;
        for(int j = 0;j<n;j++){
            if(1 << j & i){
                total += c[j];
                mx = max(mx,c[j]);
                mn = min(mn,c[j]);
            }
        }
        ans += (total >= l && total <= r && mx - mn >= x);
    }
    cout << ans;
}