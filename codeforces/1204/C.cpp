#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])
#define modulo (ll)(1e9 + 7)
#define EPS 1e-9

const int N = 100 + 9, M = 4e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int adjMat[N][N], dist[N][N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);

    int n;  cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) {
            char c; cin >> c;
            adjMat[i][j] = c == '1';
            dist[i][j] = (adjMat[i][j] ? 1 : (i == j ? 0 : OO));
        }

    for(int k = 0;k < n;k++)
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int m;  cin >> m;
    int p[m];
    for(int i = 0;i < m;i++){
        cin >> p[i];
        p[i]--;
    }

    int ok[m] = {0}, a = 0, b = 1;

    ok[0] = ok[m - 1] = 1;

    for(int i = 2;i < m;i++){
        int c = i;

        if(!(p[a] == p[c]) && dist[p[a]][p[c]] >= dist[p[a]][p[b]] + dist[p[b]][p[c]])
            b = c;
        else
            ok[b] = 1, a = b, b = c;
    }

    cout << count(ok, ok + m, 1) << '\n';
    for(int i = 0;i < m;i++)
        if(ok[i])   cout << p[i] + 1 << " ";
};