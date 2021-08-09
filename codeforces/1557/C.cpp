#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod){
    if(p == 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

int n, k;

ll total, totalEvenOdd;

ll dp[N][2];

ll solve(int i, int tight) {
    if(i == k)
        return 1;

    ll &ret = dp[i][tight];
    if(~ret)    return ret;

    ret = 0;
    if(tight){
        if(n & 1){
            ret += 1 * solve(i + 1, tight) + totalEvenOdd * solve(i + 1, tight) % modulo;
        }

        else{
            ret += 1 * solve(i + 1, !tight) + (totalEvenOdd - 1) * solve(i + 1, tight) % modulo;
        }
    }
    else{
        ret += total * solve(i + 1, tight) % modulo;
    }

    return ret % modulo;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);

        cin >> n >> k;// n numbers, k bits
        total = power(2, n, modulo);
        totalEvenOdd = power(2, (n - 1), modulo);

        cout << solve(0, 1) << '\n';
    }
}