#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 5e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
string a[N];

int dp[2][27][27];

int solve() {
    for (int i = n; i >= 0; i--) {
        for (int first = 0; first <= 26; first++) {
            for (int back = 0; back <= 26; back++) {
                int &ret = dp[i % 2][first][back];
                if (i == n) {
                    ret = -OO;
                    continue;
                }

                ret = dp[(i + 1) % 2][first][back];

                int f = a[i].front() - 'a';
                int b = a[i].back() - 'a';
                if (first == 26 || back == f) {
                    ret = max(ret, (int) a[i].size() + dp[(i + 1) % 2][(first == 26 ? f : first)][b]);
                    if (first == 26 || first == b)
                        ret = max(ret, (int) a[i].size() * (first == 26 ? f == b : 1));
                }
            }
        }
    }

    return dp[0][26][26];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t = 1;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve() << '\n';
    }
}