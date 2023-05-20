#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {

        int l, r;
        cin >> l >> r;

        int len = 1;
        while ((l << len) <= r)
            len++;

        int twos = (r / (1 << (len - 1)) - l + 1);

        int twos_and_one_three = 0;
        if (len > 1)
            twos_and_one_three += (len - 1) * max(0, (r / (1 << (len - 2)) / 3 - l + 1));

        cout << len << " " << twos + twos_and_one_three << '\n';
    }
}