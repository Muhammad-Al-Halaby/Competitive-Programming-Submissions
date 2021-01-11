#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll nCk(ll n, ll k) {
    ll ret = 1;
    for (ll i = k + 1; i <= n; i++) {
        ll d = (i - k);
        ll q = i / d;
        ll r = i - q * d;
        ret = ret * q + ret * r / d;
    }
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;   cin >> n;
    n--;

    cout << nCk(n, 11);
}