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
        int n;
        cin >> n;

        ll a[n], ones[n], inversions = 0;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            ones[i] = a[i];
            if(i)
                ones[i] += ones[i-1];

            if(a[i] == 0)
                inversions += ones[i];
        }

        ll ans = inversions;
        for(int i = 0;i < n;i++){
            int zeros = (n - (i + 1)) - (ones[n - 1] - ones[i]);
            if(a[i] == 0){
                ans = max(ans, inversions - ones[i] + zeros);
            }
            else{
                ans = max(ans, inversions - zeros + ones[i] - 1);
            }
        }

        cout << ans << '\n';
    }
}