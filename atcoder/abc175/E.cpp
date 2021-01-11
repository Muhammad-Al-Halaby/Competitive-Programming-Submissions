#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 3005, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int grid[N][N], n, m, k;

ll dp[N][N][5];

ll solve(int i, int j, int cnt){
    if(i == n)  return 0;
    if(j == m)  return 0;

    ll &ret = dp[i][j][cnt];
    if(~ret)    return ret;


    if(grid[i][j] && cnt < 3){
        ret = max(ret, grid[i][j] + solve(i, j + 1, cnt + 1));
        ret = max(ret, grid[i][j] + solve(i + 1, j, 0));
    }
    ret = max(ret, solve(i, j + 1, cnt));
    ret = max(ret, solve(i + 1, j, 0));

    return ret;
}

int r, c, v;

void go(int tc = 0){
    cin >> n >> m >> k;
    for(int i = 0;i < k;i++){
        cin >> r >> c >> v;
        r--, c--;
        grid[r][c] = v;
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);

}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}