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

        int start[n], middle[n], end[n];
        for(int i = 0;i < n;i++){
            cin >> start[i];
            middle[i] = start[i];
            end[i] = start[i] - (i + 1);
            start[i] += (i + 1);
        }

        int mx = end[n - 1], max_match[n];
        max_match[n - 1] = -OO;
        for(int i = n - 2;i >= 1;i--){
            max_match[i] = max(max_match[i + 1], middle[i] + mx);
            mx = max(mx, end[i]);
        }

        int ans = -OO;
        for(int i = 0;i < n - 2;i++)
            ans = max(ans, start[i] + max_match[i + 1]);

        cout << ans << '\n';
    }
}