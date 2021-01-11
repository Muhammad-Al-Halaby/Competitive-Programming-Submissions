#include <bits/stdc++.h>

using namespace std;

#define modulo ll (998244353)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

ll inverse(ll n){
    return power(n, modulo - 2, modulo);
}

int n, m, k;

//n - #blocks <= k
//
//#|#|#
//m|m-1|m-1
//
//---
//112
//221
//122
//211
//
//|---|---
//
//3-3 <= 1
//3-2 <= 1

ll factorial[N], inv[N];


ll nCk(int n, int k){
    if(k > n)   return 0;
    return (((factorial[n] * inv[k]) % modulo) * inv[n - k]) % modulo;
}

int main() {
    factorial[0] = 1;
    inv[0] = inverse(1);
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % modulo;
        inv[i] = inverse(factorial[i]);
    }

    cin >> n >> m >> k;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n - i > k) continue;
        ans += ((m * power(m - 1, i - 1, modulo) % modulo) * nCk(n + i - 1 - i, i - 1)) % modulo;
        ans %= modulo;
    }
    cout << ans;
}