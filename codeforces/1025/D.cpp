#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 700 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int n, gcd[N][N], dp[N][N][2];

int solve(int l, int r, bool root){
    if(l > r)   return 1;

    int &ret = dp[l][r][root];
    if(~ret)    return ret;

    ret = 0;
    for(int i = l;i <= r;i++){
        if(::gcd[i][(root ? r + 1 : l - 1)]){
            ret |= solve(l, i - 1, 1) & solve(i + 1, r, 0);
        }
    }

    return ret;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int g = __gcd(a[i], a[j]);
            ::gcd[i][j] = ::gcd[j][i] = g > 1;
        }
    }


    memset(dp, -1, sizeof dp);

    for(int i = 0;i < n;i++){
        if(solve(0, i - 1, 1) & solve(i + 1, n - 1, 0)) {
            cout << "YES";
            return 0;
        }

    }

    cout << "NO";
}