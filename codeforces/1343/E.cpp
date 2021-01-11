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

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
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


int dist[N][3], vis[N], vid;

void bfs(int src, int p){
    queue<int> q;
    q.push(src);

    vid++;
    vis[src] = vid;
    dist[src][p] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();

        neig(adj, u, e, v){
            if(vis[v] == vid)   continue;
            vis[v] = vid;
            dist[v][p] = 1 + dist[u][p];
            q.push(v);
        }
    }
}

int n, m, a, b, c, u, v;

ll p[M];

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n >> m >> a >> b >> c;

        adj.init(n);
        a--, b--, c--;

        for(int i = 1;i <= m;i++)    cin >> p[i];

        sort(p, p + m + 1);
        partial_sum(p, p + m + 1, p);

        for(int i = 0;i < m;i++){
            int u, v;   cin >> u >> v;
            u--, v--;
            adj.addBiEdge(u, v);
        }

        bfs(a, 0);
        bfs(b, 1);
        bfs(c, 2);

        ll ans = llOO;
        for(int i = 0;i < n;i++){
            int x = dist[i][0];
            int y = dist[i][1];
            int z = dist[i][2];

            if(x + y + z > m)   continue;

            ans = min(ans, p[x + y + z] + p[y]);
        }

        cout << ans << '\n';
    }
}