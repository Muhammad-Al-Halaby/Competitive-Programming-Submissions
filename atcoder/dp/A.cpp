#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

// dp[i] = minimum number of steps to reach n, starting from i

int n, h[N];

int dp[N];

int solve(int i){
    if(i == n - 1)
        return 0;

    int &ret = dp[i];
    if(~ret)    return ret;

    ret = OO;
    if(i + 1 < n)
        ret = abs(h[i] - h[i + 1]) + solve(i + 1);
    if(i + 2 < n)
        ret = min(ret, abs(h[i] - h[i + 2]) + solve(i + 2));

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> h[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0);
}