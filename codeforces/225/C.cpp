#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, x, y, c[N];

int dp[N][2][N];

//1 = white, 0 = black
int solve(int i, int prev, int w){
    if(i == m)  return (w < x ? OO : 0);

    int &ret = dp[i][prev][w];
    if(~ret)    return ret;

    ret = OO;
    if(w < y)   ret = min(ret, (prev == 1 ? n - c[i] : c[i]) + solve(i + 1, prev, w + 1));

    if(w >= x || i == 0)
        ret = min(ret, (prev == 0 ? n - c[i] : c[i]) + solve(i + 1, !prev, 1));

    return ret;
}

int main(){
    init();

    cin >> n >> m >> x >> y;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
            char c; cin >> c;
            ::c[j] += (c == '.');
        }

    memset(dp, -1, sizeof dp);
    
    cout << solve(0, 0, 0);
}