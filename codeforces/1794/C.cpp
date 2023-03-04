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
        int n;
        cin >> n;

        int a[n];
        double a_logs[n];
        double i_logs[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a_logs[i] = log(a[i]);
            i_logs[i] = log(i + 1);
            if(i)
                i_logs[i] += i_logs[i - 1];
        }

        for(int i = n - 2;i >= 0;i--){
            a_logs[i] += a_logs[i + 1];
        }

        auto check = [&](int mid, int i){
            double up = a_logs[mid] - (i + 1 < n ? a_logs[i + 1] : 0);
            int len = i - mid;
            double down = i_logs[len];
            return up - down;
        };

        for(int i = 0;i < n;i++){
            int l = 0, r = i;
            while(l <= r){
                int mid = (l + r) >> 1;
                double x = check(mid, i);
                double y = (mid + 1 > i ? -OO : check(mid + 1, i));
                if(x < y && fabs(x - y) > 1e-9){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            cout << i - l + 1 << " ";
        }
        cout << '\n';
    }

}