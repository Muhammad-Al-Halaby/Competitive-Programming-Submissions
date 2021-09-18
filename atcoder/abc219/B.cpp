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

    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    string t;   cin >> t;

    string ans = "";
    for(int i = 0;i < t.size();i++){
        ans += s[t[i] - '0' - 1];
    }

    cout << ans;
}