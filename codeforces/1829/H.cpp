#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N];

int dp[N][64][2];

int solve(int i, int bitwise_and, int pick){
    if(i == n)
        return (pick && __builtin_popcount(bitwise_and) == k);

    int &ret = dp[i][bitwise_and][pick];
    if(~ret)    return ret;

    ret = (0ll + solve(i + 1, bitwise_and & a[i], 1) + solve(i + 1, bitwise_and, pick)) % modulo;

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;

        for(int i = 0;i < n;i++)
            for(int j = 0;j < 64;j++)
                dp[i][j][0] = dp[i][j][1] = -1;

        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }

        cout << solve(0, 63, 0) << '\n';
    }
}