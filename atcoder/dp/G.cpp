#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

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



int dp[N];

int dfs(int u){
    int &ret = dp[u];
    if(~ret)    return dp[u];

    ret = 0;
    neig(adj, u, e, v)
        ret = max(ret, dfs(v));

    ret++;

    return ret;
}


int n, m, u, v;

void go(int tc){
    cin >> n >> m;
    adj.init(n);
    for(int i = 0;i < m;i++){
        cin >> u >> v;  u--, v--;
        adj.addEdge(u, v);
    }

    memset(dp, -1, sizeof dp);

    int ans = 0;
    for(int i = 0;i < n;i++)
        ans = max(ans, dfs(i));

    cout << ans - 1;
}

int main(){
    init();

    int t, tc = 1;  t = 1;//cin >> t;
    while(t--)  go(tc++);

}
