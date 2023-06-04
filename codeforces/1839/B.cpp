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

        vector<pair<int, int>> v;
        for(int i = 0;i < n;i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, -b});
        }

        sort(v.begin(), v.end());

        int on = 0, broken = 0;
        ll ans = 0;
        multiset<int> s;
        for(int i = 0;i < n;i++){
            if(v[i].first <= broken)  continue;
            ans += -v[i].second;
            on++;
            s.insert(v[i].first);
            broken = max(broken, on);
            while(s.size() && *s.begin() <= on){
                s.erase(s.begin());
                on--;
            }
        }
        cout << ans <<'\n';
    }
}