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

    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> s;
    for(int i =0 ;i < n;i++) {
        int x, y;
        cin >> x >> y;
        s.push_back({{x, y}, i});
    }

    int A;
    cin >> A;
    int a[A];
    for(int i =0 ;i < A;i++) {
        cin >> a[i];
    }

    int B;
    cin >> B;
    int b[B];
    for(int i =0 ;i < B;i++){
        cin >> b[i];
    }

    sort(s.begin(), s.end());

    int v_pos[n], h_pos[n];
    for(int i = 0, j = 0;i < n;i++){
        while(j < A && s[i].first.first > a[j])j++;
        h_pos[s[i].second] = j;
        s[i] = {{s[i].first.second, s[i].first.first}, s[i].second};
    }

    sort(s.begin(), s.end());

    for(int i = 0, j = 0;i < n;i++){
        while(j < B && s[i].first.first > b[j])j++;
        v_pos[s[i].second] = j;
    }

    map<pair<int, int>, int> mp;
    for(int i = 0;i < n;i++){
        mp[{h_pos[i], v_pos[i]}]++;
    }

    int mn = (mp.size() < 1ll * (A + 1) * (B + 1) ? 0 : n);

    int mx = 0;
    for(auto p : mp){
        mn = min(mn, p.second);
        mx = max(mx, p.second);
    }

    cout << mn << " " << mx;

}