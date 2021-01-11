#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll n, k;

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}

inline void fixMod(ll &x){
    x = ((x % modulo) + modulo) % modulo;
}

ll cnt[N] = {};

int main(){
    init();

    n = 3;

    cin >> k;

    ll ans = 0;
    for(int i = k;i >= 1;i--){
        ll mults = (k / i);
        ll localAns = power(mults, n);
        ll exclude = 0;
        for(int j = 2;j * i <= k;j++){
            exclude += cnt[i * j];  exclude %= modulo;
        }

        localAns -= exclude;    fixMod(localAns);
        cnt[i] = localAns;
        ans += localAns * i;    fixMod(ans);
    }

    cout << ans;
}