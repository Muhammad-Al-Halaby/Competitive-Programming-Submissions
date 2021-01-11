#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], sz[N];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}


ll dp[N];

int dfs(int u, int p){
    sz[u] = 1;

    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];

        if(v == p)  continue;

        sz[u] += dfs(v, u);

        dp[u] += dp[v];

    }

    dp[u] += sz[u];

    return sz[u];
}

ll ans;

void solve(int u, int p){
    ans = max(ans, dp[u]);

    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];

        if(v == p)  continue;

        dp[u] = dp[u] - n - dp[v] + (n - sz[v]);
        dp[v] = dp[v] - sz[v] + n + dp[u];
        sz[u] = n - sz[v];
        sz[v] = n;

        solve(v, u);

        swap(u, v);

        dp[u] = dp[u] - n - dp[v] + (n - sz[v]);
        dp[v] = dp[v] - sz[v] + n + dp[u];
        sz[u] = n - sz[v];
        sz[v] = n;

        swap(u, v);
    }
}

int u, v;

int main(){
    init();

    cin >> n;

    initGraph();

    for(int i = 0;i < n - 1;i++){
        cin >> u >> v;  u--, v--;
        addBiEdge(u, v);
    }

    dfs(0, -1);
    solve(0, -1);

    cout << ans;
}