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
        int n, m;
        cin >> n >> m;

        int z[n];
        for(int i = 0;i < n;i++){
            z[i] = 0;
        }

        int a[m], b[m];
        for(int i = 0;i < m;i++){
            cin >> a[i] >> b[i];
            a[i]--, b[i]--;
        }

        int q;
        cin >> q;
        int x[q];
        for(int i = 0;i < q;i++){
            cin >> x[i];
            x[i]--;
        }

        auto check = [&](int k) {
            for (int i = 0; i <= k; i++) {
                z[x[i]] = 1;
            }

            partial_sum(z, z + n, z);

            int ret = 0;
            for (int i = 0; i < m; i++) {
                int sum = z[b[i]] - (a[i] - 1 >= 0 ? z[a[i] - 1] : 0);
                int len = b[i] - a[i] + 1;
                int zeros = len - sum;
                if (sum > zeros) {
                    ret = 1;
                    break;
                }
            }

            for (int i = 0; i < n; i++) {
                z[i] = 0;
            }

            return ret;
        };

        int l = 0, r = q - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        cout << (l == q ? -1 : l + 1)  << '\n';
    }
}