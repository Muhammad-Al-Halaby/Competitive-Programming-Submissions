#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])


typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


ll dp[1005][1005];

ll nCk(int n, int k){
    if(n < k)   return 0;
    if(k == 0 || n == 0)  return 1;

    ll &ret = dp[n][k];
    if(~ret)    return ret;

    return ret = nCk(n - 1, k - 1) + nCk(n - 1, k);
}

int main(){
    init();

    memset(dp, -1, sizeof dp);

    int n;  cin >> n;

    cout << nCk(n, 5) + nCk(n, 6) + nCk(n, 7);
}