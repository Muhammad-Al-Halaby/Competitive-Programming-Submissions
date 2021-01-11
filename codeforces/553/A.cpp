#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e4 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
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

ll factorial[N], inv[N];

ll nCk(int n, int k){
    if(k > n)   return 0;
    return (((factorial[n] * inv[k]) % modulo) * inv[n - k]) % modulo;
}

ll nPr(int n, int r){
    if(r > n)   return 0;
    return (factorial[n] * inv[n - r]) % modulo;
}

ll iterative_nPr(int n, int r){
    if(r > n)   return 0;
    ll ret = 1;
    for(int i = (n - r + 1);i <= n;i++)
        ret *= i;
    return ret;
}

ll iterative_nCk(ll n, ll k){
    ll ret = 1;
    for(ll i = k + 1;i <= n;i++){
        ll d = (i - k);
        ll q = i / d;
        ll r = i - q * d;
        ret = ret * q + ret * r / d;
    }
    return ret;
}

int main() {

    factorial[0] = 1;
    inv[0] = inverse(1);
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % modulo;
        inv[i] = inverse(factorial[i]);
    }

    int k;  cin >> k;

    ll ans = 1, n = 0;
    for(int i = 0;i < k;i++){
        int c;  cin >> c;
        ans *= nCk(n + c - 1, c - 1);
        ans %= modulo;
        n += c;
    }
    cout << ans;
}