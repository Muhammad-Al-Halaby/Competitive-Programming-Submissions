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

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}


ll spots, n;

ll dp[60][5][60][2];

ll solve(int i, int last, int cnt, int ok){
    if(cnt > n) return 0;
    if(i == spots + 1)  return ok;

    ll &ret = dp[i][last][cnt][ok];
    if(~ret)    return ret;

    ret = 0;
    for(int t = 1;t <= 4;t++) {
        int newCnt = (t == last ? cnt + 1 : 1);
        ret += solve(i + 1, t, newCnt, ok | newCnt == n);
    }
    return ret;
}


int main(){
    init();

    cin >> n;

    spots = 2 * n - 2;

    memset(dp, -1, sizeof dp);

    cout << solve(1, 0, 0, 0);
}