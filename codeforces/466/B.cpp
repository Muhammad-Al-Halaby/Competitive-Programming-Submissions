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
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 2e5 + 9, M = 1e4 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


ll cumu[N];

int main(){
    init();

    ll n, a, b; cin >> n >> a >> b;
    ll ans = 1e18, na = a;
    for(ll i = min(a, b);i * i <= 6 * n;i++){
        ll nx = ceil((6.0 * n) / i);
        if(!((i >= a && nx >= b) || (i >= b && nx >= a)))  continue;
        if(nx >= b && i * nx >= 6 * n && i * nx < ans){
            ans = i * nx;
            if(i >= a && nx >= b)   na = i;
            else na = nx;
        }
    }

    if(ans == 1e18) ans = a * b;
    cout << ans << '\n' << na << " " << ans / na;
}