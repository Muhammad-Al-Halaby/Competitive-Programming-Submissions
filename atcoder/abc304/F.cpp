#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<ll> divisors;
void getDivisors(ll n){
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n / i != i)
                divisors.push_back(n / i);
        }
    }
}

int D;
int n;
string s;
ll dp[N];

ll solve(int i){
    if(i == D + 1){
        return 1;
    }

    ll &ret = dp[i];
    if(~ret)    return ret;

    //Attend
    ret = solve(i + 1);
    //Don't Attend
    bool ok = 1;
    for(int j = i;j <= n;j += D){
        if(s[j - 1] == '.'){
            ok = 0;
            break;
        }
    }
    if(ok)  ret += solve(i + 1);

    ret %= 998244353;

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    // 46 divisors
    cin >> n;
    cin >> s;

    getDivisors(n);
    sort(divisors.begin(), divisors.end());

    ll ans[n+1] = {};
    for(auto d : divisors){
        if(d == n)  continue;
        memset(dp, -1, sizeof dp);
        D = d;
        ans[d] = solve(1);
    }

    for(auto d : divisors) {
        if(d == n)  continue;
        for(auto d2 : divisors) {
            if(d2 == n)  continue;
            if(d2 <= d) continue;
            if(d2 % d == 0){
                ans[d2] -= ans[d];
                ans[d2] += 998244353;
                ans[d2] %= 998244353;
            }
        }
    }

    ll fans = 0;
    for(auto d : divisors) {
        if(d == n)  continue;
        fans += ans[d];
        fans %= 998244353;
    }

    cout << fans;
}