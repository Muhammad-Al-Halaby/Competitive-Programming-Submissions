#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

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


int subtreeSz[N], degree[N], mark[M];

void dfs(int u, int p) {
    subtreeSz[u] = 1;
    neig(adj, u, e, v) {
        if (v == p) continue;
        dfs(v, u);
        subtreeSz[u] += subtreeSz[v];
    }
}

int total;

int dfs2(int u, int p) {
    int ret = 0;
    neig(adj, u, e, v) {
        if (v == p) continue;
        ret += dfs2(v, u);
        if (degree[u] == 2 && degree[u] == degree[v] and (total - subtreeSz[v] >= 3 and subtreeSz[v] >= 3)) {
            mark[e] = 1;
            mark[e ^ 1] = 1;
            subtreeSz[u] -= subtreeSz[v];
            ret += subtreeSz[v];
            total -= subtreeSz[v];
//            cout << u + 1 << " " << v + 1 << endl;
        }
    }
    subtreeSz[u] -= ret;
    return ret;
}


int vis[N];
vector<int> ans;

int dfs3(int u, int p) {
    vis[u] = 1;
    int cnt = 1;
    neig(adj, u, e, v) {
        if (v == p || mark[e]) continue;
        cnt += dfs3(v, u);
    }
    return cnt;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    adj.initGraph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.addBiEdge(u, v);
        degree[u]++;
        degree[v]++;
    }

    dfs(0, -1);
    total = n;
    dfs2(0, -1);
    for (int i = 0; i < n - 1; i++) {
        if (!vis[i])
            ans.push_back(dfs3(i, -1));
    }

    sort(ans.begin(), ans.end());

    for (auto x: ans)
        cout << x - 1 << " ";

}