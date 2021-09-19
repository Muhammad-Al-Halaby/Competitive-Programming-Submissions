#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, capacity, w[N], v[N];

ll dp[105][100005];

ll solve(int i, int rem){
    if(rem < 0) return llOO;

    if(i == n)  return rem == 0 ? 0 : llOO;

    ll &ret = dp[i][rem];
    if(~ret)    return ret;

    ret = min(w[i] + solve(i + 1, rem - v[i]), solve(i + 1, rem));

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> capacity;

    for(int i = 0;i < n;i++)
        cin >> w[i] >> v[i];

    memset(dp, -1, sizeof dp);

    for(int i = 1e5;i >= 0;i--){
        ll ans = solve(0, i);
        if(ans > capacity) continue;
        return cout << i, 0;
    }

}