#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, x, y, a[N], b[N];

int dp[305][305][305];

int solve(int i, int remx, int remy){
    if(remx == 0 && remy == 0)
        return 0;
    if(i == n)
        return OO;

    int &ret = dp[i][remx][remy];
    if(~ret)    return ret;

    ret = min(1 + solve(i + 1, max(0, remx - a[i]), max(0, remy - b[i])), solve(i + 1, remx, remy));

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> x >> y;
    for(int i = 0;i < n;i++)
        cin >> a[i] >> b[i];

    memset(dp, -1, sizeof dp);

    int ans = solve(0, x, y);
    cout << (ans >= OO ? -1 : ans);
}