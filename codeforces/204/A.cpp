#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p < 0)   return 0;
    if(p == 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

string n;
int len;

ll dp[18][2][10];

ll solve(int i, int tight, int match){
    if(i == len)
        return 1;

    ll &ret = dp[i][tight][match];
    if(~ret)    return ret;

    ret = 0;
    for(int digit = 0;digit <= 9;digit++){
        //first digit
        if(i == 0 && digit == 0)
            continue;

        //last digit
        if(i != 0 && i == len - 1 && digit != match)
            continue;

        //don't exceed the number
        if(tight && digit > n[i] - '0')   break;

        ret += solve(i + 1, (tight ? !(digit < n[i] - '0') : 0) , (i == 0 ? digit : match));
    }

    return ret;
}

ll calc(ll len){
    int ret[] = {0, 9};
    if(len <= 2)
        return ret[len - 1];
    return 9 + power(10, len - 2) - 1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof dp);

    a--;
    n = to_string(a);
    len = n.size();
    ll l = solve(0, 1, 0) + calc(len);

    memset(dp, -1, sizeof dp);

    n = to_string(b);
    len = n.size();
    ll r = solve(0, 1, 0) + calc(len);

    cout << r - l;
}