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

    int n, k;   cin >> n >> k;

    string s;   cin >> s;

    vector<pair<string, string>> v;

    int x = 2 * s.size();

    while(s.size()){
        string t = "";
        while(t.size() < x)
            t += s;
        while(t.size() > x)
            t.pop_back();

        v.push_back({t, s});
        s.pop_back ();
    }

    sort(v.begin(), v.end());

    string t = "";
    while(t.size() < k)
        t += v[0].second;

    while(t.size() > k)
        t.pop_back();

    cout << t;
}