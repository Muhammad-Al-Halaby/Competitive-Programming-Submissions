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


vector<vector<int>> divisors(N);

void getDivisors(){
    for(int i = 1;i < N;i++){
        for(int j = 1;j * j <= i;j++) {
            if (i % j == 0) {
                divisors[i].push_back(j);
                if (i / j != j)
                    divisors[i].push_back(i / j);
            }
        }
    }
}


int a[N], freq[N], ans[N];

void dfs(int u, int p, int depth, int mx){

    int mx1 = 0, mx2 = 0;
    for(auto &d : divisors[a[u]])   freq[d]++;
    for(auto &d : divisors[a[u]])   mx1 = max(mx1, (freq[d] == depth + 1 ? d : 0));
    for(auto &d : divisors[a[u]])   mx2 = max(mx2, (freq[d] == depth ? d : 0));

    ans[u] = max({mx1, mx2, mx});

    neig(adj, u, e, v){
        if(v == p)  continue;
        dfs(v, u, depth + 1, mx1);
    }

    for(auto &d : divisors[a[u]])   freq[d]--;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    getDivisors();

    int n;  cin >> n;
    adj.initGraph(n);

    for(int i = 0;i < n;i++)    cin >> a[i];

    for(int i = 0;i < n - 1;i++){
        int u, v;   cin >> u >> v;
        u--, v--;
        adj.addBiEdge(u, v);
    }

    dfs(0, -1, 0, 0);

    for(int i = 0;i < n;i++)    cout << ans[i] << " ";
}