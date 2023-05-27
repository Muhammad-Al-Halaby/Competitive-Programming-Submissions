#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, x, y, z;
string s;

ll dp[N][2];

ll solve(int i, int caps){
    if(i == n)
        return 0;

    ll &ret = dp[i][caps];
    if(~ret)    return ret;

    ret = llOO;
    if(s[i] == 'a'){
        if(caps)    ret = min(y + solve(i + 1, 1), x + z + solve(i + 1, 0));
        else ret = min(x + solve(i + 1, 0), z + y + solve(i + 1, 1));
    }
    else{
        if(!caps)    ret = min(y + solve(i + 1, 0), x + z + solve(i + 1, 1));
        else ret = min(x + solve(i + 1, 1), z + y + solve(i + 1, 0));
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> x >> y >> z >> s;

    n = s.size();

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0);
}