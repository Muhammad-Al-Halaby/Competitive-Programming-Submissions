#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 3e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[N];
int mat[N][N];

int main() {
    int n, m;   cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u, v;   cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        mat[u][v] = 1;
    }

    ll ans = 0;
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            if(u == v)  continue;
            int cnt = 0;
            for(int i = 0; i < adj[u].size(); i++){
                int k = adj[u][i];
                if(k == v)  continue;
                cnt += mat[k][v];
            }
            ans += 1ll * cnt * (cnt - 1) / 2;
        }
    }
    cout << ans;
}