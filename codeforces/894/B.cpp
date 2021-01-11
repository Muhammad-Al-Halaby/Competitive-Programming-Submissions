#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p == 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m, k; cin >> n >> m >> k;
    n--, m--;
    if(!~k && (n & 1) ^ (m & 1))    cout << 0;
    else cout << power(power(2, n, modulo), m, modulo);
}