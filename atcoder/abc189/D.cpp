#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
string s[70];

ll dp[70][2];

ll solve(int i, int state){
    if(i == n)
        return state == 1;

    ll &ret = dp[i][state];
    if(~ret)    return ret;

    ret = 0;
    for(int x = 0;x <= 1;x++)
        ret += solve(i + 1, (s[i] == "AND" ? state & x : state | x));

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> s[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) + solve(0, 1);
}