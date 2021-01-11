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

int n, m, k, dp[N][N][M][2];

string a, b;

int solve(int i, int j, int k, bool prefix){
    if(i == n || j == m)    return 0;

    int &ret = dp[i][j][k][prefix];
    if(~ret)    return ret;

    ret = 0;
    if(a[i] == b[j]){
        if(k)   ret = max(ret, 1 + solve(i + 1, j + 1, k - 1, 1));
        if(prefix)    ret = max(ret, 1 + solve(i + 1, j + 1, k, 1));
    }

    ret = max(ret, solve(i + 1, j, k, 0));
    ret = max(ret, solve(i, j + 1, k, 0));

    return ret;
}


int main(){
    init();

    cin >> n >> m >> k >> a >> b;

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, k, 0);
}