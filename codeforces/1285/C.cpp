#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc){
    ll x;   cin >> x;

    ll n = x;

    vector<ll> f;
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            ll factor = 1;
            while(n % i == 0){
                n /= i;
                factor *= i;
            }
            f.push_back(factor);
        }
    }

    f.push_back(n);


    int sz = f.size();

    ll ans = llOO;
    for(int i = 0;i < (1 << sz);i++){
        ll mx = 1;
        for(int j = 0;j < sz;j++){
            if((i >> j) & 1){
                mx *= f[j];
            }
        }

        if(mx >= x / mx)
            ans = min(ans, mx);
    }

    cout << x / ans << " " << ans;
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)  go(tc++);
}