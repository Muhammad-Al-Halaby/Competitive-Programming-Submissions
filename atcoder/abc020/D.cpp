#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void fixMod(ll &n){
    n = ((n % modulo) + modulo) % modulo;
}

vector<ll> factors;

void factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            while(n % i == 0)   n /= i;
            factors.push_back(i);
        }
    }
    if(n > 1)
        factors.push_back(n);
}

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

ll coprime(ll k, ll range){
    vector<ll> factors;
    for(int i = 0;i < ::factors.size();i++)
        if(k % ::factors[i] == 0)
            factors.push_back(::factors[i]);

    ll ret = range * (range + 1) / 2;   fixMod(ret);

    int sz = factors.size();
    for(int i = 1;i < (1 << sz);i++){
        bool parity = __builtin_popcount(i) & 1;
        ll lcm = 1;
        for(int j = 0;j < sz;j++){
            if(((i >> j) & 1) && k % factors[j] == 0)
                lcm *= factors[j];
        }

        if(lcm == 1)    continue;

        ll cnt = range / lcm;
        ll sumOfMults = (cnt * (cnt + 1) / 2) % modulo * lcm; fixMod(sumOfMults);
        ret += (parity ? -1 : 1) * sumOfMults;  fixMod(ret);
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;   cin >> n >> k;

    factorize(k);
    getDivisors(k);

    ll ans = 0;
    for(int i = 0;i < divisors.size();i++){
        ll range = n / divisors[i];
        ans += coprime(k / divisors[i], range) * k % modulo;   fixMod(ans);
    }

    cout << ans;
}