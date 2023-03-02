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
        string s;
        cin >> s;
        int i = 0, cnt = 0;
        while(i < n && tolower(s[i]) == 'm') i++, cnt |= 1;
        while(i < n && tolower(s[i]) == 'e') i++, cnt |= 2;
        while(i < n && tolower(s[i]) == 'o') i++, cnt |= 4;
        while(i < n && tolower(s[i]) == 'w') i++, cnt |= 8;
        cout << (i == n && cnt == 15 ? "YES" : "NO") << '\n';
    }
}