#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
    init();

    ll a,b,ans = 1;
    cin >> a >> b;
    
    if(b - a >= 5)
        return cout << 0, 0;
    else
        for(ll i = a+1; i < b+1;i++)
            ans = ((ans % 10) * (i%10))%10;
    cout << ans;
}