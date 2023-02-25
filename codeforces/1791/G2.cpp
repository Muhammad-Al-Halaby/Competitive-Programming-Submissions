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
    while (t--) {
        int n, c;
        cin >> n >> c;

        pair<ll, int> a[n + 1];
        a[0] = {0, 0};
        for(int i = 1;i <= n;i++){
            cin >> a[i].first;

            a[i].second = a[i].first + i;
            a[i].first += min(i, n - i + 1);
        }

        sort(a, a + n + 1);

        for(int i = 1;i <= n;i++)
            a[i].first += a[i - 1].first;

        auto check = [&](int idx, int prefix){
            ll temp = c - a[idx].second;
            ll sum = a[prefix].first - (idx <= prefix ? a[idx].first - a[idx - 1].first : 0);
            return sum <= temp;
        };

        int ans = 0;
        for(int i = 1;i <= n;i++){
            int l = 0, r = n;
            while(l <= r){
                int mid = (l + r) >> 1;

                if(check(i, mid))
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            ans = max(ans, r + (i > r));
        }

        cout << ans << '\n';
    }
}