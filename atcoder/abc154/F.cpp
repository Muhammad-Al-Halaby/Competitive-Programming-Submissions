#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])


typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

ll factorial[N], inv[N];

ll inverse(ll n){
    return power(n, modulo - 2, modulo);
}

ll nCk(int n, int k){
    if(k > n)   return 0;
    return ((factorial[n] * inv[k]) % modulo * inv[n - k]) % modulo;
}

int main(){
    init();

    factorial[0] = 1;
  	inv[0] = inverse(1);
    for(int i = 1;i < N;i++){
        factorial[i] = (factorial[i - 1] * i) % modulo;
    	inv[i] = inverse(factorial[i]);
    }
    
  	int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;

    ll ans = 0;
    for(int i = r1 + 1;i <= r2 + 1;i++){
        ans += (nCk(i + c2, c2) - nCk(i + c1 - 1, c1 - 1) + modulo) % modulo;
        ans %= modulo;
    }

    cout << ans;
}