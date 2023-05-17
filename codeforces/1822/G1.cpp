#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

map<int, int> cnt;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n];
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        
        int mx = *max_element(a, a + n);

        ll ans = 0;

        for (auto x: s)
            ans += 1ll * cnt[x] * (cnt[x] - 1) * (cnt[x] - 2);

        for (auto x: s){
            ll mx_b = sqrt(1e6 / x);
            for (int b = 2; b <= mx_b; b++) {
                if(cnt.count(b * x) == 0 || cnt.count(b * b * x) == 0)
                    continue;
                ans += 1ll * cnt[x] * cnt[b * x] * cnt[b * b * x];
            }
        }

        cout << ans << '\n';
    
        for (int i = 0; i < n; i++)
            cnt[a[i]]--;
    }
}