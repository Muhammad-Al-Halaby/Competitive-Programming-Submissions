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
        int n, x;
        cin >> n >> x;

        int a[n + 1];
        iota(a + 1, a + 1 + n, 1);
        a[1] = x;
        a[n] = 1;
        if (x == n) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " \n"[i == n];
            continue;
        }

        if (x != n && n % x != 0) {
            cout << -1 << '\n';
            continue;
        }

        a[x] = n;

        int j = x;
        for (int i = x + 1; i < n; i++) {
            if (n % i == 0 && i % j == 0) {
                a[j] = i;
                a[i] = n;
                j = i;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];

    }
}