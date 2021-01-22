#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 20 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
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

ll nCk(ll n, ll k){
    ll ret = 1;

    for(ll i = k + 1;i <= n;i++) {
        ret = (ret * (i % modulo)) % modulo;
    }

    return ret * inv[n - k];
}

void init(){
    factorial[0] = 1;
    inv[0] = inverse(1);
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % modulo;
        inv[i] = inverse(factorial[i]);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();

    ll n, s;    cin >> n >> s;

    ll a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

/*
    a1+a2+a3+....+an = s
    To calculate this: 0 <= a1 <= a[1], 0 <= a2 <= a[2], 0 <= a3 <= a[3], ...., 0 <= an <= a[n]
    I calculated this: 0 <= a1 <= s, 0 <= a2 <= s, 0 <= a3 <= s, ...., 0 <= an <= s
    Then excluded this: a[1] < a1 <= s, a[2] < a2 <= s, a[3] < a3 <= s, ...., a[n] < an <= s
*/

    ll ans = 0;
    for(int i = 0;i < (1 << n);i++){
        int parity = __builtin_popcount(i) & 1;
        ll total = s;

        for(int j = 0;j < n;j++){
            if((i >> j) & 1 ^ 1)    continue;
            total -= a[j] + 1;
        }

        if(total < 0)   continue;

        ans += (parity ? -1 : 1) * nCk(total + n - 1, total);
        ans %= modulo;
        ans += modulo;
        ans %= modulo;
    }

    cout << ans;
}