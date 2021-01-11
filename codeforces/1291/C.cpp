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
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 3500 + 9, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int dp[N][N], n, m, k, a[N], vis[N][N], vid;
int solve(int i, int j){
    int pos = i + (n - 1) - j;
    if(pos == m - 1)    return max(a[i], a[j]);


    int &ret = dp[i][j];
    if(vis[i][j] == vid)    return ret;
    vis[i][j] = vid;

    if(pos < k){
        ret = max(solve(i + 1, j), solve(i, j - 1));
    }
    else{
        ret = min(solve(i + 1, j), solve(i, j - 1));
    }

    return ret;
}
int main(){
    init();
 
    int t;  cin >> t;
    while(t--){
        vid++;
        cin >> n >> m >> k;
        for(int i = 0;i < n;i++)    cin >> a[i];
        cout << solve(0, n - 1) << '\n';
    }
}