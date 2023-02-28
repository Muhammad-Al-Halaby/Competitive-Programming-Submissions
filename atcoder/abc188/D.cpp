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

    int n, C;
    cin >> n >> C;

    int a[n], b[n], c[n];
    set<int> s;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> c[i];
        s.insert(a[i]);
        s.insert(b[i] + 1);
    }

    map<int, int> stl;
    map<int, int> lts;
    int cnt = 0;
    for(auto x : s){
        stl[cnt] = x;
        lts[x] = cnt;
        cnt++;
    }

    ll prefix_sum[s.size() + 1] = {};
    for(int i = 0;i < n;i++){
        int l = lts[a[i]];
        int r = lts[b[i] + 1];
        prefix_sum[l] += c[i];
        prefix_sum[r] -= c[i];
    }

    partial_sum(prefix_sum, prefix_sum + s.size() + 1, prefix_sum);

    ll ans = 0;
    for(int i = 0;i < s.size() - 1;i++){
        ll len = (i + 1 < s.size() ? stl[i + 1] - stl[i] : 1);
        ans += len * min(prefix_sum[i], 1ll * C);
    }

    cout << ans;
}