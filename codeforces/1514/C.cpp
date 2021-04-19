#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;  cin >> n;

    vector<ll> v;
    ll mult = 1;
    for(ll i = 1;i < n - 1;i++){
        if(__gcd(n, i) == 1) {
            v.push_back(i);
            mult *= i;
            mult %= n;
        }
    }

    if(((n - 1) * mult) % n == 1)
        v.push_back(n - 1);

    cout << v.size() << '\n';
    for(auto x : v)
        cout << x << " ";
    
}