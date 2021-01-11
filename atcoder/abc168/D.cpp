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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
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

int vis[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[0] = 0;
    while(q.size()){
        int u = q.front();  q.pop();
        neig(adj, u, e, v){
            if(vis[v] != -1)    continue;
            vis[v] = u;
            q.push(v);
        }
    }
}

int n, m, u, v;

int main(){
    init();


    memset(vis, -1, sizeof vis);

    cin >> n >> m;
    adj.init(n);
    for(int i = 0;i < m;i++){
        cin >> u >> v;  u--, v--;
        adj.addBiEdge(u, v);
    }

    bfs(0);

    for(int i = 0;i < n;i++)    if(vis[i] == -1) return cout << "No", 0;

    cout << "Yes\n";
    for(int i = 1;i < n;i++)
        cout << vis[i] + 1 << '\n';
}