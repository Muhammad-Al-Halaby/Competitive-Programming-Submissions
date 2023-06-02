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

        vector<int> miners;
        vector<int> diamonds;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) {
                miners.push_back(abs(y));
            } else {
                diamonds.push_back(abs(x));
            }
        }

        sort(miners.begin(), miners.end());
        sort(diamonds.begin(), diamonds.end());


        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += hypot(miners[i], diamonds[i]);
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }
}