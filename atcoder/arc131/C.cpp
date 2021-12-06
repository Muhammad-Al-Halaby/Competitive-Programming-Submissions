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

    int n;
    cin >> n;
    int a[n], xorr = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xorr ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        if (xorr == a[i])
            return cout << "Win", 0;
    }

    cout << (n & 1 ? "Win" : "Lose");
}