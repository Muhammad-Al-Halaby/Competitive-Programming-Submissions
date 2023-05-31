#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

// dp[i][and_sofar] = number of subsequences from i to n - 1 starting with bitwise_and = and_sofar

int n, k, a[N];

int dp[N][64];

int solve(int i, int and_sofar) {
    if (i == n) {
        return (__builtin_popcount(and_sofar) == k);
    }

    int &ret = dp[i][and_sofar];
    if (~ret) return ret;

    ret = solve(i + 1, and_sofar) + solve(i + 1, and_sofar & a[i]);

    ret %= modulo;

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for(int i = 0;i < n;i++)
            for(int j = 0;j < 64;j++)
                dp[i][j] = -1;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << solve(0, 63) - (k == 6) << '\n';
    }
}