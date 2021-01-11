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

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll iterative_nCk(ll n, ll k){
    if(k > n)  return 0;

    ll ret = 1;
    for(ll i = k + 1;i <= n;i++){
        ll d = (i - k);
        ll q = i / d;
        ll r = i - q * d;
        ret = ret * q + ret * r / d;
    }
    return ret;
}

int main(){
    init();

    int n, m, t;    cin >> n >> m >> t;

    ll ans = 0;
    for(int i = 4;i <= n && t - i >= 1;i++){
        ans += iterative_nCk(n, i) * iterative_nCk(m, t - i);
    }

    cout << ans;
}