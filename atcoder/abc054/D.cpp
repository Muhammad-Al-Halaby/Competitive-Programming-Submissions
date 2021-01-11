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

const int N = 50, M = 500, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ma, mb, a[N], b[N], c[N], dp[N][M][M];

int solve(int i, int sa, int sb){
    if(i == n){
        if(sa && sb){
            int g = __gcd(sa, sb);
            sa /= g, sb /= g;
        }
        return (sa == ma && sb == mb) ? 0 : OO;
    }

    int &ret = dp[i][sa][sb];
    if(~ret)    return ret;

    return ret = min(solve(i + 1, sa, sb), c[i] + solve(i + 1, sa + a[i], sb + b[i]));
}

int main(){
    init();

    cin >> n >> ma >> mb;
    for(int i = 0;i < n;i++)    cin >> a[i] >> b[i] >> c[i];
    memset(dp, -1, sizeof dp);
    cout << (solve(0, 0, 0) == OO ? -1 : solve(0, 0, 0));
}