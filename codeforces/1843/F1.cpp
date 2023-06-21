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
 
int a[N], mx[N], mn[N];
 
void dfs(int u, int mx_so_far, int mx_ending_here){
    mx_ending_here = mx_ending_here + a[u];
 
    if(mx_so_far < mx_ending_here)
        mx_so_far = mx_ending_here;
 
    if(mx_ending_here < 0)
        mx_ending_here = 0;
 
    mx[u] = mx_so_far;
    neig(adj, u, e, v){
        dfs(v, mx_so_far, mx_ending_here);
    }
}
 
void dfs2(int u, int mn_so_far, int mn_ending_here){
    if(mn_ending_here > 0)
        mn_ending_here = min(a[u], 0);
    else
        mn_ending_here += a[u];
 
    mn_so_far = min(mn_so_far, mn_ending_here);
 
    mn[u] = mn_so_far;
 
    neig(adj, u, e, v){
        dfs2(v, mn_so_far, mn_ending_here);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
 
        adj.initGraph(n);
        a[0] = 1;
        int cnt = 1;
        vector<pair<int, int>> q;
        for(int i = 0;i < n;i++){
            char c;
            cin >> c;
            if(c == '+'){
                int u, k;
                cin >> u >> k;
                u--;
                a[cnt] = k;
                adj.addEdge(u, cnt++);
            }
            else{
                int u, v, k;
                cin >> u >> v >> k;
                u--, v--;
                q.push_back({v, k});
            }
        }
 
        dfs(0, -OO, 0);
        dfs2(0, OO, OO);
 
        for(int i = 0;i < q.size();i++){
            auto [v, k] = q[i];
            if(mn[v] <= k && k <= mx[v])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}