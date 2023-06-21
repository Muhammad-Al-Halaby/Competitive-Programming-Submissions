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
        int n, k;
        cin >> n >> k;

        int msb = 0;
        for(int i = 30;i >= 0;i--)
            if((n >> i) & 1){
                msb = i;
                break;
            }

        if(k < msb + 1){
            cout << (1LL << k) << '\n';
            continue;
        }

        ll ans = 0;
        for(int i = msb;i >= 0;i--){
            if((n >> i) & 1)
                ans += (1LL << i);
        }

        ans += 1;

        cout << ans << '\n';
    }
}