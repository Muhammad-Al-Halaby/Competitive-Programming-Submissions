#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e7 + 9, M = 1e7 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {

        int n;


        cin >> n;

        n *= 2;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        int ok = 1;
        for (int i = 0; i < n - 1; i++) {
            int sum = a[i] + a[n - 1];

            multiset<int> s;
            for (int i = 0; i < n; i++)
                s.insert(a[i]);


            ok = 1;
            while (ok && s.size()) {
                int mx = *s.rbegin();
                if (s.find(sum - mx) != s.end()) {
                    s.erase(s.find(sum - mx));
                    if (s.find(mx) != s.end()) {
                        s.erase(s.find(mx));
                        sum = mx;
                    }
                    else
                        ok = 0;
                }
                else
                    ok = 0;
            }

            if (ok) {
                for (int i = 0; i < n; i++) {
                    s.insert(a[i]);
                }
                sum = a[i] + a[n - 1];
                cout << "YES\n" << sum << '\n';
                while (s.size()) {
                    int mx = *s.rbegin();
                    cout << mx << " " << sum - mx << '\n';
                    s.erase(s.find(sum - mx));
                    s.erase(s.find(mx));
                    sum = mx;
                }
                break;
            }
        }

        if(!ok) cout << "NO\n";
    }
}