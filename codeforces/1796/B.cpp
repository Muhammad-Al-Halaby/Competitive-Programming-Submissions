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

    while (t--) {
        string a, b;
        cin >> a >> b;

        if (a[0] == b[0])
            cout << "YES\n" << a[0] << "*" << '\n';
        else if (a.back() == b.back())
            cout << "YES\n" << "*" << a.back() << '\n';
        else {

            string ans = "";
            for (int i = 0; i < a.size() - 1; i++) {
                for (int j = 0; j < b.size() - 1; j++) {
                    if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
                        ans = "YES\n*" + string(1, a[i]) + string(1, a[i + 1]) + "*";
                        break;
                    }
                    if (ans != "") break;
                }
            }

            if (ans == "")
                cout << "NO\n";
            else
                cout << ans << '\n';
        }
    }
}