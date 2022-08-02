#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int adj[n][n] = {};
    for(int i = 0;i < m;i++) {
        int u, v;   cin >> u >> v;
        u--, v--;
        adj[v][u] = adj[u][v] = 1;
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = j + 1;k < n;k++){
                ans += adj[i][j] && adj[j][k] && adj[i][k];
            }
        }
    }

    cout << ans;
}