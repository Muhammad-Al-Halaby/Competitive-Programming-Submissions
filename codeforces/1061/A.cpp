#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1
#define EPS 1e-7
#define go continue;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //cout.sync_with_stdio(0);
    //cout.tie(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    ll n, s, ans = 0;
    cin >> n >> s;
    while(s){
        ans += s / n;
        s %= n;
        n--;
    }
    cout << ans;
}
