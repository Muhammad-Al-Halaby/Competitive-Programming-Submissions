#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n, m;
    cin >> n;

    pair<int, int> a[2 * n];

    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
    for (int i = 0; i < n; i++) cin >> a[i + n].first, a[i + n].second = i + 1;

    cin >> m;

    sort(a, a + 2 * n);

    vector<int> factorials;

    ll len = 0, repetitions = 0, rep = 0;
    for (int i = 0; i + 1 < 2 * n; i++) {
        len++;
        if (a[i].first != a[i + 1].first) {
            factorials.push_back(len);
            repetitions += rep;
            len = rep = 0;
        }
        if (a[i] == a[i + 1])
            rep++;
    }

    len++;
    factorials.push_back(len);
    repetitions += rep;

    ll ans = 1;
    for (auto v : factorials) {
        for (int i = 2; i <= v; i++) {
            int temp = i;
            if (i & 1 ^ 1) {
                while (temp % 2 == 0 && repetitions-- > 0) temp /= 2;
            }
            ans *= temp;
            ans %= m;
        }
    }

    cout << ans;
}