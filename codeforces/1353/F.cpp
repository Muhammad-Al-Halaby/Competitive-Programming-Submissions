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

const int N = 109, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m;

ll a[N][N], dp[N][N];

ll solve(){
    memset(dp, llOO, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ll cost = a[i][j] - (a[0][0] + (i + j));
            if(cost < 0)    continue;
            if(i)   dp[i][j] = cost + dp[i - 1][j];
            if(j)   dp[i][j] = min(dp[i][j], cost + dp[i][j - 1]);
        }
    }
    return dp[n - 1][m - 1];
}

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin >> a[i][j];

        ll ans = llOO, s = a[0][0];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                ll newStart = a[i][j] - (i + j);
                if(newStart > s)    continue;
                a[0][0] = newStart;
                ans = min(ans, s - newStart + solve());
            }
        }
        cout << ans << '\n';
    }
}