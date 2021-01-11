#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
	int head[N], nxt[M], to[M], ne, n;
	void init(int n) {
		memset(head, -1, n * sizeof(head[0]));
		ne = 0;
		this->n = n;
	}
	void addEdge(int f, int t) {
		nxt[ne] = head[f];
		to[ne] = t;
		head[f] = ne++;
	}
	void addBiEdge(int f, int t) {
		addEdge(f, t);
		addEdge(t, f);
	}
	int addNode() {
		head[++n] = 0;
		return n;
	}
} adj;

struct DSU{
    int parent[N], sz[N], diameter[N];
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

int vis[N], vid;

pii dfsDiameter(int u, int p){
    vis[u] = vid;

    int diameter = 0, mxDepth[3] = {-1, -1, -1};
    neig(adj, u, e, v){
        if(v == p)  continue;
        auto p = dfsDiameter(v, u);
        diameter = max(diameter, p.F);
        mxDepth[0] = p.S + 1;
        sort(mxDepth, mxDepth + 3);
    }

    for(int i = 0;i < 3;i++)    if(mxDepth[i] == -1)    mxDepth[i] = 0;

    diameter = max(diameter, mxDepth[1] + mxDepth[2]);

    return {diameter, mxDepth[2]};
}


int n, m, q, u, v, diameter[N];

int main(){
    init();

    cin >> n >> m >> q;

    adj.init(n);
    dsu.init(n);

    for(int i = 0;i < m;i++){
        cin >> u >> v;  u--, v--;
        adj.addBiEdge(u, v);
        dsu.join(u, v);
    }

    vid++;
    for(int i = 0;i < n;i++){
        if(vis[i] != vid)
            diameter[dsu.find(i)] = dfsDiameter(i, -1).F;
    }

    for(int i = 0;i < q;i++){
        int t;  cin >> t;
        if(t == 1){
            cin >> u;   u--;
            cout << diameter[dsu.find(u)] << '\n';
        }
        else{
            cin >> u >> v;  u--, v--;
            int p1 = dsu.find(u);
            int p2 = dsu.find(v);
            if(p1 == p2)    continue;
            int x = max({diameter[p1], diameter[p2], ((diameter[p1] + 1)/ 2) + ((diameter[p2] + 1) / 2) + 1});
            dsu.join(u, v);
            diameter[dsu.find(u)] = x;
        }
    }
}