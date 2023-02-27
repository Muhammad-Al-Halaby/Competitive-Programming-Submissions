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

int n, a, b;

void bfs(int s, int skip, vector<int> &xors) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{s, -1}, 0});
    while (q.size()) {
        pair<pair<int, int>, int> f = q.front();
        q.pop();
        int u = f.first.first;
        int p = f.first.second;
        int x = f.second;

        if (!(s == b && u == b)) xors.push_back(x);
        neig(adj, u, e, v) {
            if (v == p || v == skip) continue;
            q.push({{v, u}, x ^ adj.cost[e]});
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        a--, b--;

        adj.initGraph(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj.addBiEdge(u, v, w);
        }

        vector<int> v1;
        vector<int> v2;

        bfs(a, b, v1);
        bfs(b, -1, v2);

        set<int> s(v2.begin(), v2.end());

        int ok = 0;
        for (int i = 0; i < v1.size(); i++)
            if (s.find(v1[i]) != s.end()) {
                ok = 1;
                break;
            }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}