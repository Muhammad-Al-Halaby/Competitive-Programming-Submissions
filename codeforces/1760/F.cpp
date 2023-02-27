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

    while(t--) {
        ll n, c, d;
        cin >> n >> c >> d;

        ll a[n];
        for(int i = 0;i < n;i++)
            cin >> a[i];

        sort(a, a + n);
        reverse(a, a + n);

        partial_sum(a, a + n, a);

        auto check = [&](ll k){
            ll sum = a[min(k, n - 1)];
            ll x = ceil(1.0 * c / sum);
            ll days = (x - 1) * (k + 1);
            ll total_minus_last = (x - 1) * sum;
            for(int i = 0;i <= min(k, n - 1);i++){
                if(total_minus_last >= c)   break;
                total_minus_last += (a[i] - (i ? a[i - 1] : 0));
                days++;
            }
            return days <= d;
        };

        ll l = 1, r = 1e9;
        while(l <= r){
            ll mid = (l + r) >> 1;

            if(check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        if(r == 1e9)
            cout << "Infinity" << '\n';
        else if(r == 0)
            cout << (check(0) ? "0" : "Impossible") << '\n';
        else
            cout << r << '\n';
    }
}