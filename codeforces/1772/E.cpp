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
        int n;
        cin >> n;

        int c1 = 0, c2 = 0, intersect = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            int p = 0;

            if (x != i + 1) c1++, p = 1;
            if (x != n - i) c2++, intersect += p;
        }

        int free1 = c1 - intersect;
        int free2 = c2 - intersect;

        if (free1 + intersect <= free2)
            cout << "First\n";
        else if (free2 + intersect + 1 <= free1)
            cout << "Second\n";
        else
            cout << "Tie\n";
    }
}