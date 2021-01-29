#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void fixMod(ll &n){
    n = (n % modulo + modulo) % modulo;
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

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;   cin >> n >> k;

    getDivisors(k);

    sort(divisors.rbegin(), divisors.rend());

    vector<ll> gcdSum(divisors.size());

    ll ans = 0;
    for(int i = 0;i < divisors.size();i++){
        ll cnt = n / divisors[i];
        gcdSum[i] = divisors[i] * (cnt * (cnt + 1) / 2);    fixMod(gcdSum[i]);
        for(int j = 0;j < i;j++) {
            if(divisors[j] % divisors[i] == 0){
                gcdSum[i] -= gcdSum[j]; fixMod(gcdSum[i]);
            }
        }
        ans += (k / divisors[i]) * gcdSum[i];   fixMod(ans);
    }

    cout << ans;
}