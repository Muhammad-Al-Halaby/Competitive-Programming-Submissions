#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, x, a[N];

ll dp[N][21][3];
int vis[N][21][3], vid;

ll solve(int i, int rem, int state) {
    if (rem < 0)
        return -llOO;

    if (i == n)
        return (rem == 0 ? 0 : -llOO);

    if (state > 2)
        return -llOO;

    ll &ret = dp[i][rem][state];
    if (vis[i][rem][state] == vid) return ret;
    vis[i][rem][state] = vid;

    ret = solve(i, rem, state + 1);

    if (state == 1) {
        ret = max(ret, (a[i] + x) + solve(i + 1, rem - 1, state));
        ret = max(ret, (a[i] - x) + solve(i + 1, rem, state));
    } else {
        ret = max(ret, solve(i + 1, rem - 1, state));
        ret = max(ret, solve(i + 1, rem, state));
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        vid++;

        cin >> n >> k >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << solve(0, k, 0) << '\n';
    }
}