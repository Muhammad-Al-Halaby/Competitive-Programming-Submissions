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

const int N = 3e4 + 9, M = 609, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, d, coins[N], dp[N][M];

int solve(int i, int j){
    if(i > 30000) return 0;

    int diff = j - d + 300;

    int &ret = dp[i][diff];
    if(~ret)    return ret;

    ret = solve(i + j, j);
    ret = max(ret, solve(i + j + 1, j + 1));
    if(j > 1)
        ret = max(ret, solve(i + j - 1, j - 1));

    ret += coins[i];

    return ret;
}

int main(){
    init();

    cin >> n >> d;
    for(int i = 0, x;i < n;i++) cin >> x, coins[x]++;

    memset(dp, -1, sizeof dp);

    cout << solve(d, d);
}