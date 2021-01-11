#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 2e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
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

int main() {
    factorial[0] = 1;
    inv[0] = inverse(1);
    for(int i = 1;i < N;i++) {
        factorial[i] = (factorial[i - 1] * i) % modulo;
        inv[i] = inverse(factorial[i]);
    }

    int k;  cin >> k;
    string s;   cin >> s;
    int n = s.size();

    ll ans = 0;
    for(int i = n;i <= n + k;i++){
        ans += nCk(n + k, i) * power(25, n + k - i, modulo);
        ans %= modulo;
    }
    cout << ans;
}