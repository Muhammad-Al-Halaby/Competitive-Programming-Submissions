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

int cnt;

int vis[N];

void dfs(int u){
    vis[u] = 1;
    cnt++;
    if(cnt >= 1e6)  return;
    neig(adj, u, e, v){
        if(vis[v])  continue;
        dfs(v);
        if(cnt >= 1e6)  break;
    }
    vis[u] = 0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    adj.initGraph(n);

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.addBiEdge(u, v);
    }

    dfs(0);

    cout << min(cnt, (int)1e6);
}