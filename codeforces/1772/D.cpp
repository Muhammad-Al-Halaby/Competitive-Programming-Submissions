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
        int n;
        cin >> n;
        ll a[n];

        for(int i =0;i < n;i++)
            cin >> a[i];


        auto check = [&](ll x){
            ll b[n], sorted = 1;
            for(int j = 0;j < n;j++){
                b[j] = abs(a[j] - x);
                if(j)
                    sorted &= b[j] >= b[j - 1];
            }
            return sorted;
        };

        ll mx = 1e9;
        for(int i = 1;i < n;i++){
            if(a[i] > a[i - 1]) {
                mx = min(mx, a[i - 1] + (a[i] - a[i - 1]) / 2);
            }
        }

        ll l = 0, r = mx;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        cout << (l == mx + 1 ? -1 : l) << '\n';
    }
}