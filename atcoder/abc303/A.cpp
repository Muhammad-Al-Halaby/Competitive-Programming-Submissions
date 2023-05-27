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

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    replace(s.begin(), s.end(), 'l', '1');
    replace(t.begin(), t.end(), 'l', '1');
    replace(s.begin(), s.end(), 'o', '0');
    replace(t.begin(), t.end(), 'o', '0');

    cout << (s == t ? "Yes" : "No");
}