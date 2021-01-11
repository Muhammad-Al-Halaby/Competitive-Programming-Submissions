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

const int N = 4e3+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int dp[N][N], mp[M], vis[N], vid;

int main(){
    init();

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    int cnt = 1;
    for(int i = 0;i < n;i++){
        if(mp[a[i]] == 0)    mp[a[i]] = cnt++;
        a[i] = mp[a[i]];
    }

    int ans = 0;
    for(int i = 1;i < n;i++){
        vid++;
        for(int j = i - 1;~j;j--){
            if(vis[a[j]] == vid)    continue;
            vis[a[j]] = vid;
            dp[a[i]][a[j]] = 1 + dp[a[j]][a[i]];
            ans = max(ans, dp[a[i]][a[j]]);
        }
    }

    cout << ans + 1;
}