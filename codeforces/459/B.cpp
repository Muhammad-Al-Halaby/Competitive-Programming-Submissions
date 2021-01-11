#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n;
    cin >> n;

    int b[n], mn = 1e9, mx = 1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += b[i] == mn;
        y += b[i] == mx;
    }

    cout << mx - mn << " " << (mx != mn ? 1ll * x * y : 1ll * x * (x - 1) / 2) << '\n';
}