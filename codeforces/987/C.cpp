#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 3e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, s[N], c[N], bestCost[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        cin >> c[i];

    memset(bestCost, OO, sizeof bestCost);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[j] > s[i])
                bestCost[i] = min(bestCost[i], c[j]);

    int ans = OO;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i] < s[j])
                ans = min(ans, c[i] + c[j] + bestCost[j]);

    cout << (ans >= OO ? -1 : ans);
}