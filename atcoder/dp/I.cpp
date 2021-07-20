#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 3e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
double p[N], dp[N][N];

double solve(int i, int rem){
    if(i == n)  return rem == 0;


    double &ret = dp[i][rem];
    if(!isnan(ret))  return ret;

    ret = 0;
    if(rem){
        ret = p[i] * solve(i + 1, rem - 1);
    }

    ret += (1 - p[i]) * solve(i + 1, rem);

    return ret;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> p[i];

    memset(dp, -1, sizeof dp);

    double ans = 0;
    for(int i = n / 2 + 1;i <= n;i++){
        ans += solve(0, i);
    }

    cout << fixed << setprecision(10) << ans;
}