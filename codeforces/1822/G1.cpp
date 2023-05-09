#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;
int cnt[(int) 1e6];
int visited[(int) 1e6], vid;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        vid++;

        int n;
        cin >> n;

        int a[n];
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (visited[a[i]] != vid) {
                visited[a[i]] = vid;
                cnt[a[i]] = 0;
            }
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        
        int mx = *max_element(a, a + n);

        ll ans = 0;

        for (auto x: s)
            ans += 1ll * cnt[x] * (cnt[x] - 1) * (cnt[x] - 2);

        for (int i = 0; i < n; i++) {
            for (int b = 2; b <= 1e3; b++) {
                if (1ll * b * b * a[i] > mx) break;

                if (visited[b * a[i]] != vid) cnt[b * a[i]] = 0;
                if (visited[b * b * a[i]] != vid) cnt[b * b * a[i]] = 0;

                ans += 1ll * cnt[b * a[i]] * cnt[b * b * a[i]];
            }
        }

        cout << ans << '\n';
    }
}