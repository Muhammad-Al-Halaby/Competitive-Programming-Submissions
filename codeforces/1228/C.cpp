#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 1e3 + 5, M = 600, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll power(ll b, ll p, ll mod){
    if(p == 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}


ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    if(p & 1)res *= b;
    return res;
}

set<ll> factors;
void factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            factors.insert(i);
            while(n % i == 0)   n /= i;
        }
    }
    if(n != 1)
        factors.insert(n);
}

int main(){
    init();

    ll x, n;    cin >> x >> n;
    factorize(x);
    
    ll ans = 1;
    for(auto p : factors){
        ll mxK = ceil(log(n)) / log(p);
        ll cumulative = 0;
        for(int k = mxK;k >= 0;k--){
            ll cnt = n / power(p, k);
            ll actual = (cnt - cumulative);
            cumulative += actual;
            ll pk = power(p, k) % modulo;
            ans = (ans * power(pk, actual, modulo)) % modulo;
        }
    }
    cout << ans;
}