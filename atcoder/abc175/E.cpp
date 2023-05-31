#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 3e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, k;

int grid[N][N];

ll dp[N][N][4];

ll solve(int i, int j, int cnt){
    if(cnt == 3) return 0;

    if(i == n || j == m){
        return 0;
    }

    ll ret = grid[i][j] + max(solve(i + 1, j, 0), solve(i, j + 1, cnt + (grid[i][j] != 0)));

    ret = max({ret, solve(i + 1, j, 0), solve(i, j + 1, cnt)});

    return ret;
}

ll solve(){
    for(int i = n;i >= 0;i--){
        for(int j = m;j >= 0;j--){
            for(int cnt = 3;cnt >= 0;cnt--){
                ll &ret = dp[i][j][cnt];

                if(i == n || j == m || cnt == 3){
                    dp[i][j][cnt] = 0;
                    continue;
                }

                ret = grid[i][j] + max(dp[i + 1][j][0], dp[i][j + 1][cnt + (grid[i][j] != 0)]);

                ret = max({ret, dp[i + 1][j][0], dp[i][j + 1][cnt]});
            }
        }
    }
    return dp[0][0][0];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    for(int i = 0;i < k;i++){
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        grid[x][y] = v;
    }

    cout << solve();
}