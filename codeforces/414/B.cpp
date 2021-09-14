#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k;

ll dp[2005][2005];

ll solve(){
    for(int i = k;i >= 1;i--){
        for(int prev = n;prev >= 1;prev--){
            if(i == k){
                dp[i][prev] = 1;
                continue;
            }
            for(int j = prev;j <= n;j += prev){
                dp[i][prev] += dp[i + 1][j];
                while(dp[i][prev] >= modulo)    dp[i][prev] -= modulo;
            }
        }
    }

    ll ret = 0;
    for(int i = 1;i <= n;i++) {
        ret += dp[1][i];
        ret %= modulo;
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;

    cout << solve() << '\n';
}