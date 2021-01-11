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

const int N = 1e6, M = 1e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


ll power(ll b, ll e, ll mod){
    if(e == 1)  return b;
    ll ans = power(b, e / 2, mod);
    ans *= ans; ans %= mod;
    if(e & 1)   ans *= b;
    return ans % mod;
}

//iif p is prime, gcd(a, p) == 1;
ll modInv1(ll a, ll p){
    return power(a, p - 2, p);
}

ll fac[N], mod[N];

ll modInv(ll a, ll p){
    if(mod[a] != -1)    return mod[a];
    return mod[a] = modInv1(fac[a], p);
}

int main(){
    init();

    memset(mod, -1, sizeof mod);
    fac[0] = 1;
    for(int i = 1;i < N;i++){
        fac[i] = (i * fac[i - 1]) % modulo;
    }

    ll n, m, a, b; cin >> n >> m >> a >> b;

    ll ans = 0;
    for(int d = 0;d < n - a;d++){
        ll right = ((fac[d + b] * modInv(b, modulo)) % modulo) * modInv(d, modulo);

        ll down;
        if(d == n - a - 1)
            down = (fac[(n - d - 1) + m - b - 1] * modInv(n - d - 1, modulo) % modulo) * modInv(m - b - 1, modulo);
        else
            down = (fac[(n - d - 1) + m - b - 2] * modInv(n - d - 1, modulo) % modulo) * modInv(m - b - 2, modulo);

        right %= modulo;        down %= modulo;
        ans += (right * down);  ans %= modulo;
    }


    cout << ans;

}