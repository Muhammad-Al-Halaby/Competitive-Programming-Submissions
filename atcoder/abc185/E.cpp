#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N], b[N];

ll dp[N][N];

ll solve(int i, int j){
    if(i == n || j == m)
        return (n - i) + (m - j);

    ll &ret = dp[i][j];
    if(~ret)    return ret;

    ret = llOO;
    ll x = !(a[i] == b[j]) + solve(i + 1, j + 1);
    ll y = 1 + solve(i, j + 1);
    ll z = 1 + solve(i + 1, j);

    return ret = min({x, y, z});
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 0;i < m;i++)    cin >> b[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0);
}