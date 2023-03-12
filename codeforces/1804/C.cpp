#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, x, p;
        cin >> n >> x >> p;

        int ok = 0;

        for (ll i = 1; i <= min(2 * n, p); i++) {
            ll temp = x + (i * (i + 1)) / 2;
            if (temp >= 0 && temp % n == 0) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}