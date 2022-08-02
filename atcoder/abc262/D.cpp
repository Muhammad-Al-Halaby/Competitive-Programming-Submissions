#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 105, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;

ll a[N], dp[N][N][N], vis[N][N][N], vid, m;

ll solve(int i, int mod, int pick){
    if(i == n || pick == 0)
        return (mod == 0 ? (pick == 0) : 0);

    ll &ret = dp[i][mod][pick];

    if(vis[i][mod][pick] == vid)
        return ret;

    vis[i][mod][pick] = vid;

    ret = solve(i + 1, (mod + a[i]) % m, pick - 1) + solve(i + 1, mod, pick);

    ret %= 998244353;

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> a[i];

    ll ans = 0;
    for(int i = 1;i <= n;i++){
        vid++;
        m = i;
        ans += solve(0, 0, i);
        ans %= 998244353;
    }

    cout << ans;
}