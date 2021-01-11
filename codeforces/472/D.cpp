#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])
#define modulo (ll)(1e9 + 7)
#define EPS 1e-9

const int N = 2e3 + 9, M = 4e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
    int n, ne, head[N], nxt[M], to[M], cost[M];

    void initGraph(int n) {
        memset(head, -1, n * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t, int c) {
        to[ne] = t;
        cost[ne] = c;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
} adj;


struct DSU{
    int parent[N], sz[N];
    int components, mxcomponent;

    void init(int n){
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
        components = n;
        mxcomponent = 1;
    }

    int find(int u){
        return (parent[u] == u) ? u : parent[u] = find(parent[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v)  return;

        if(sz[u] > sz[v])   swap(u ,v);

        parent[u] = v;
        sz[v] += sz[u];

        components--;
        mxcomponent = max(mxcomponent, sz[v]);
    }


    bool isInSameGroup(int u, int v){
        return find(u) == find(v);
    }

    int getSize(int u){
        return sz[find(u)];
    }
} dsu;

int dist[N][N], from[M], to[M], cost[M], sorted[M];

bool dfs(int u, int p, ll cost, int src){
    bool ret = (u != src ? dist[u][src] > 0 && dist[u][src] == dist[src][u] && dist[src][u] == cost : dist[u][u] == 0);
    neig(adj, u, e, v){
        if(v == p)  continue;
        ret &= dfs(v, u, cost + adj.cost[e], src);
    }
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

//    freopen("portals.in","r",stdin);

    int n;  cin >> n;

    adj.initGraph(n);
    dsu.init(n);

    int edge = 0;
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            cin >> dist[u][v];
            if(u != v){
                from[edge] = u;
                to[edge] = v;
                cost[edge] = dist[u][v];
                sorted[edge] = edge;
                edge++;
            }
        }
    }

    sort(sorted, sorted + edge, [&](int a, int b){
        return cost[a] < cost[b];
    });

    for(int j = 0;j < edge;j++){
        int i = sorted[j];
        int u = from[i], v = to[i], c = cost[i];
        if(dsu.isInSameGroup(u, v)) continue;
        dsu.join(u, v);
        adj.addBiEdge(u, v, c);
    }

    int ok = 1;
    for(int u = 0;u < n;u++){
        ok &= dfs(u, -1, 0, u);
    }

    cout << (ok ? "YES" : "NO");
};