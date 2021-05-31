#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], cost[M];

void initGraph(int n) {
    memset(head, -1, (n + 1) * sizeof head[0]);
    ne = 0;
    ::n = n;
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


int vis[N], cnt;

int dfs(int u){
    if(vis[u])  return 0;


    vis[u] = 1;
    cnt++;

    int ret = cnt == n;

    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];
        ret += dfs(v);
    }

    vis[u] = 0;
    cnt--;

    return ret;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;   cin >> n >> m;

    initGraph(n);

    for(int i = 0;i < m;i++){
        int u, v;   cin >> u >> v;
        u--, v--;
        addBiEdge(u, v);
    }

    cout << dfs(0);
}