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

int a[N];

ll dfs1(int u, int p, ll x) {
    int cnt = 0;
    neig(adj, u, e, v) {
        if (v == p) continue;
        cnt++;
    }

    ll _lcm = x;
    neig(adj, u, e, v) {
        if (v == p) continue;
        _lcm = lcm(_lcm, dfs1(v, u, (u == 0 ? x : cnt * x)));
    }

    return _lcm;
}

bool overflow(ll x, ll y){
    return !(y == 0 || x <= LLONG_MAX / y);
}

ll dfs2(int u, int p, ll x, ll mid) {
    int cnt = 0;
    neig(adj, u, e, v) {
        if (v == p) continue;
        cnt++;
    }

    ll ret = (cnt != 0 ? 0 : (!overflow(x, mid) && x * mid <= a[u] ? a[u] - x * mid : llOO));
    neig(adj, u, e, v) {
        if (v == p) continue;
        ret += dfs2(v, u, (u == 0 ? x : x / cnt), mid);
        ret = min(ret, llOO);
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;  cin >> n;

    adj.initGraph(n);

    for(int i = 0;i < n;i++)    cin >> a[i];

    for(int i = 0; i < n - 1; i++) {
        int u, v;   cin >> u >> v;
        u--, v--;
        adj.addBiEdge(u, v);
    }

    ll root = dfs1(0, -1, 1);

    ll l = 0, r = llOO;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(dfs2(0, -1, root, mid) < llOO)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << dfs2(0, -1, root, r);
}