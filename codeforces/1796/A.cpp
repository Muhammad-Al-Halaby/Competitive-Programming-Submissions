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

    string pattern = "FBFFBFFBFBFFBFFBF";

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ok = pattern.find(s);

        cout << (ok != string::npos ? "YES" : "NO") << '\n';
    }
}