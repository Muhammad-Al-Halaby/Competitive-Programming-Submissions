#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll fixMod(ll a, ll b) {
    return (a % b + b) % b;
}

void pushBack(ll &h, ll base, ll mod, char c) {
    h = ((h * base) % mod + c) % mod;
}

void pushFront(ll &h, ll p, ll mod, char c) {
    h = (h + (c * p) % mod) % mod;
}

void popFront(ll &h, ll p, ll mod, char c) {
    h = fixMod((h - (p * c) % mod), mod);
}

void popBack(ll &h, ll inv, ll mod, char c) {
    h = (fixMod(h - c, mod) * inv) % mod;
}


ll power(ll b, ll p, ll mod) {
    if (p == 0) return 1;
    ll res = power(b, p / 2, mod);
    res *= res;
    res %= mod;
    if (p & 1) res *= b;
    return res % mod;
}

ll inverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    string t;
    cin >> t;

    int m = 2 * n;
    ll p = 1;//power
    ll h1 = 0; //hash of s1
    ll h2 = 0; //hash of s2
    ll h3 = 0; //hash of s2
    ll base = 131; //base for hashing
    ll mod = 1e9 + 7; //modulo for hashing
    ll inv = inverse(base, mod);

    for (int i = 0; i < n; i++) {
        pushBack(h2, base, mod, t[n - i - 1]);
        pushBack(h3, base, mod, t[m - n + i]);
        if (i) p = (p * base) % mod;
    }
  
    ll pp = p, ppp = p;
    for (int i = n; i < m; i++) {
        if (fixMod(fixMod(h1 * pp, mod) + h3, mod) == h2) {
            string s = "";
            for (int j = i - n; j < (i - n) + n; j++)
                s += t[j];
            reverse(s.begin(), s.end());
            cout << s << '\n' << i - n;
            return 0;
        }

        popBack(h2, inv, mod, t[i - n]);
        pushBack(h1, base, mod, t[i - n]);

        popFront(h3, ppp, mod, t[i]);
        pushFront(h2, p, mod, t[i]);
        if(i != n)  pp = (pp * inv) % mod;
        ppp = (ppp * inv) % mod;
    }

    cout << -1;
}