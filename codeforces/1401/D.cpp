#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
    int n, ne, head[N], nxt[M], to[M];

    void initGraph(int n) {
        memset(head, -1, (n + 1) * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t) {
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v) {
        addEdge(u, v);
        addEdge(v, u);
    }
} adj;


int n;

vector<ll> weights;

int dfs(int u, int p) {
    int ret = 1;
    neig(adj, u, e, v) {
        if (v == p) continue;

        int cnt = dfs(v, u);
        weights.push_back(1ll * cnt * (n - cnt));

        ret += cnt;
    }
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        adj.initGraph(n);
        weights.clear();

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj.addBiEdge(u, v);
        }

        dfs(0, -1);
        sort(weights.begin(), weights.end());

        int m;
        cin >> m;

        int p[m];
        for (int i = 0; i < m; i++)
            cin >> p[i];

        sort(p, p + m);

        ll ans = 0;
        if (m <= n - 1) {
            for (int i = 0; i < n - 1; i++) {
                if (i < (n - 1) - m)
                    ans += weights[i];
                else
                    ans += 1ll * weights[i] % modulo * p[i - ((n - 1) - m)] % modulo;

                ans %= modulo;
            }
        } else {
            for (int i = 0; i < n - 2; i++) {
                ans += 1ll * weights[i] % modulo * p[i] % modulo;
                ans %= modulo;
            }

            ll largest = 1;
            for (int i = n - 2; i < m; i++) {
                largest *= p[i];
                largest %= modulo;
            }

            ans += weights[n - 2] % modulo * largest % modulo;
            ans %= modulo;
        }
        cout << ans << '\n';
    }
}