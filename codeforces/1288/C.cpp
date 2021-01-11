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

const int N = 1e3 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, m;

ll dp[N][N];

int solve(){
    for(int a = 1;a <= m;a++)
        for(int b = 1;b <= m;b++)
            if(a <= b)  dp[a][b] = 1;

    for(int i = 0;i < n;i++){
        for(int a = m;a >= 1;a--){
            for(int b = 1;b <= m;b++){
                dp[a][b] = dp[a][b] + dp[a][b - 1] + dp[a + 1][b] - dp[a + 1][b - 1];
                dp[a][b] += modulo;
                while(dp[a][b] >= modulo)   dp[a][b] -= modulo;
            }
        }
    }
    return dp[1][m];
}
int main(){
    init();
    cin >> m >> n;
    cout << solve();
}