#include <bits/stdc++.h>

using namespace std;

#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

const int N = 2e5 + 9, M = 1e6 + 9;

struct Adj {
    int n, ne, head[N], nxt[M], to[M], cost[M];

    void initGraph(int n) {
        memset(head, -1, (n + 1) * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t, int c = 0) {
        to[ne] = t;
        cost[ne] = c;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v, int c = 0) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
} adj;

int ans;

void dfs(int u, int p, int prev, int step) {
    neig(adj, u, e, v) {
        if (v == p) continue;
        dfs(v, u, adj.cost[e], step + (prev > adj.cost[e]));
    }
    ans = max(ans, step);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.initGraph(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj.addBiEdge(u, v, i);
        }

        ans = 0;
        dfs(0, -1, 0, 1);

        cout << ans << '\n';
    }
}