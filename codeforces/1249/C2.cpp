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

const int N = 2e5+5, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    //res %= modulo;
    if(p & 1)res *= b;
    return res;// % modulo;
}



int main(){
    init();

    ll powersof3[39] = {1};
    for(int i = 1;i <= 38;i++){
        powersof3[i] = powersof3[i - 1] + power(3, i);
    }

    int q;  cin >> q;
    while(q--){
        ll  n;  cin >> n;

        ll ans = 0;
        while(true){

            int logy = log(n) / log(3);
            ll val = powersof3[logy] - (logy ? powersof3[logy - 1] : 0);

            if(val == n){
                ans += val;
                break;
            }
            if(powersof3[logy] == n){
                ans += powersof3[logy];
                break;
            }
            if(powersof3[logy] < n){
                ans += powersof3[logy + 1] - powersof3[logy];
                break;
            }

            ans += val;
            n -= val;
        }

        cout << ans << '\n';
    }
}