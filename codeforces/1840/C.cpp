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

    int t;
    cin >> t;

    while(t--){
        int n, k, q;
        cin >> n >> k >> q;

        int a[n];
        for(int i = 0;i < n;i++)
            cin >> a[i];

        ll ans = 0;
        for(int i = 0, j = 0;i < n;i++){
            while(j < i || (j < n && a[j] <= q))j++;
            ll k_ways = (j - i) - k + 1;
            if(k_ways <= 0) continue;
            ans += k_ways * (k_ways + 1) / 2;
            i = j;
        }

        cout << ans << '\n';
    }
}