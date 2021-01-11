#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 505, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, m, b, mod;
int a[N];

ll dp[2][N][N];

ll solve(){
    memset(dp, 0, sizeof dp);
    for(int i = 0;i <= b;i++)
        dp[0][0][i] = dp[1][0][i] = 1;

    for(int i = 0;i < n;i++)
        for(int j = 1;j <= m;j++)
            for(int k = 0;k <= b;k++){
                dp[i & 1][j][k] = ((k - a[i] >= 0) ? dp[i & 1][j - 1][k - a[i]] : 0) + dp[!(i & 1)][j][k];
                while(dp[i & 1][j][k] >= mod) dp[i & 1][j][k] -= mod;
            }
    return dp[(n - 1) & 1][m][b];
}


int main(){
    init();
    cin >> n >> m >> b >> mod;
    for(int i = 0;i < n;i++)    cin >> a[i];
    cout << solve();
}