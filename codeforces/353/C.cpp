#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, a[N];

string s;

int dp[N][2];

int solve(int i, int tight){
    if(i == n)  return 0;

    int &ret = dp[i][tight];
    if(~ret)    return ret;

    if(tight){
        if(s[i] == '1') {
            ret = solve(i + 1, 0);
            ret = max(ret, a[n - i - 1] + solve(i + 1, tight));
        }
        else{
            ret = solve(i + 1, tight);
        }
    }
    else{
        ret = a[n - i - 1] + solve(i + 1, tight);
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> a[i];

    cin >> s;

    reverse(s.begin(), s.end());

    memset(dp, -1, sizeof dp);

    cout << solve(0, 1);
}