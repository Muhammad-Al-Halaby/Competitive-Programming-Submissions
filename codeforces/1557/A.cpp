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

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;

        ll a[n] = {0};
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        sort(a, a + n);
        partial_sum(a, a + n, a);


        double ans = -1e18;
        for(int i = 0;i < n - 1;i++){
            ll sum1 = a[i];
            ll cnt1 = i + 1;
            ll sum2 = a[n - 1] - a[i];
            ll cnt2 = n - cnt1;

            ans = max(ans, 1.0 * sum1 / cnt1 + sum2 / cnt2);
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }

}