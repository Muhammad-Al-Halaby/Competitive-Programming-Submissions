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


int main(){
    init();


    ll n, m, k;   cin >> n >> m >> k;

    ll mn = min(n, m);
    m = max(n , m);
    n = mn;

    auto check = [&](ll x){
        ll ans = 0, rnk = 0;
        for(int i = 1;i <= n;i++){
            ll mn = min(i * m, x - 1);
            ans += mn / i;
            if(x % i == 0 && x <= i * m)
                rnk++;
        }
        if(k - ans <= rnk)
            return 1;
        return 0;
    };

    ll l = 1, r = 1e12;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}