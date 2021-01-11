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

const int N = 250, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll dp[N][N][N];

int x, y, z;
ll r[N], g[N], b[N];


ll solve(int i, int j, int k){
    ll &ret = dp[i][j][k];
    if(~ret)    return ret;

    ret = 0;

    ll s1 = 0, s2 = 0, s3 = 0;
    if(i < x && j < y)
        s1 = r[i] * g[j] + solve(i + 1, j + 1, k);

    if(i < x && k < z)
        s2 = r[i] * b[k] + solve(i + 1, j, k + 1);

    if(j < y && k < z)
        s3 = g[j] * b[k] + solve(i, j + 1, k + 1);

    return ret = max({ret, s1, s2, s3});
}


void go(int tc = 0){
    
    cin >> x >> y >> z;
    
    for(int i = 0;i < x;i++)    cin >> r[i];
    for(int i = 0;i < y;i++)    cin >> g[i];
    for(int i = 0;i < z;i++)    cin >> b[i];

    sort(r, r + x, greater<>());
    sort(g, g + y, greater<>());
    sort(b, b + z, greater<>());

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0) << '\n';
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