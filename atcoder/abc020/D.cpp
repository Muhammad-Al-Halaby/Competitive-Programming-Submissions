#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<pair<ll, int>> factors;

void factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0)   n /= i, cnt++;
            factors.push_back({i, cnt});
        }
    }
    if(n > 1)
        factors.push_back({n, 1});
}

ll power(ll b, ll p, ll mod = 2e18){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    //res %= mod;
    if(p & 1)res *= b;
    return res;// % mod;
}

int factorCount(int x, int factor){
    int ret = 0;
    while(x % factor == 0) x /= factor, ret++;
    return ret;
}


void fixMod(ll &n) {
    n %= modulo;
}

void fixModSub(ll &n){
    n = ((n % modulo) + modulo) % modulo;
}

int lcms[M];

void generate_lcms(){
    int sz = factors.size();
    for(int i = 1;i < (1 << sz);i++) {
        int LCM = 1;
        for (int j = 0; j < sz; j++) {
            if (((i >> j) & 1) ^ 1) continue;
            LCM *= factors[j].first;
        }
        lcms[i] = LCM;
    }
}

ll sum_of_coprime(ll n){
    ll total = n * (n + 1) / 2; fixMod(total);
    int sz = factors.size();
    for(int i = 1;i < (1 << sz);i++){
        int LCM = lcms[i], parity = __builtin_popcount(i) & 1;
        ll cnt = n / LCM;
        ll sumOfMults = LCM * cnt * (cnt + 1) / 2;  fixMod(sumOfMults);
        total += (parity ? -1 : +1) * sumOfMults;   fixModSub(total);
    }
    return total;
}


ll ans;
int n;

vector<int> logfac;


vector<vector<ll>> fp;

void solve(int i, ll lcm, ll rem){
    if(i == factors.size()){
        ll sum_of_cop = sum_of_coprime(n / lcm);
        fixMod(lcm);
        ll ret = ((sum_of_cop * lcm) % modulo) * rem;    fixMod(ret);

        ans += ret; fixMod(ans);

        return;
    }

    int sz = factors.size();

    ll mx = logfac[i];
    for(int j = 0;j <= mx;j++){
        ll x = 1, y = 1;
        if(sz >= i + 1){
            int remPow = max(0, factors[i].second - j);
            x = fp[i][remPow];   fixMod(rem);
            ll val = fp[i][j];
            if(lcm > n / val) return;
            y = val;
        }
        solve(i + 1, lcm * y, (rem * x) % modulo);
        if(factors.size() < i + 1)  return;
    }
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int k;  cin >> n >> k;

    factorize(k);
    generate_lcms();

    logfac.resize(factors.size());
    fp.resize(factors.size());


    for(int i = 0;i < factors.size();i++){
        ll fac = factors[i].first;
        int lg = log(n) / log(fac);
        logfac[i] = max(factors[i].second, lg);
        fp[i].resize(logfac[i] + 1);
        fp[i][0] = 1;
        for(int j = 1; j <= logfac[i]; j++){
            fp[i][j] = fp[i][j - 1] * fac;
        }
    }

    solve(0, 1, 1);

    cout << ans << endl;
}