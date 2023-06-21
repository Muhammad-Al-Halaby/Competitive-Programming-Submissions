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
        string s1, s2;
        cin >> s1 >> s2;
 
        int n = s1.size();
 
        int t, q;
        cin >> t >> q;
 
        int cntEqual = 0;
 
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                cntEqual++;
        }
 
        set<pair<int, int>> blocked;
        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
 
            while (!blocked.empty() && (*(blocked.begin())).first <= i) {
                auto[x, y] = *(blocked.begin());
                if (s1[y] == s2[y])
                    cntEqual++;
                blocked.erase(blocked.begin());
            }
 
            if (type == 1) {
                int pos;
                cin >> pos;
                pos--;
                blocked.insert({i + t, pos});
 
                if (s1[pos] == s2[pos]) {
                    cntEqual--;
                }
            } else if (type == 2) {
                int a, pos1, b, pos2;
                cin >> a >> pos1 >> b >> pos2;
                pos1--;
                pos2--;
 
                if (a == 1 && b == 1) {
                    cntEqual -= (s1[pos1] == s2[pos1]);
                    cntEqual -= (s1[pos2] == s2[pos2]);
                    swap(s1[pos1], s1[pos2]);
                    cntEqual += (s1[pos1] == s2[pos1]);
                    cntEqual += (s1[pos2] == s2[pos2]);
                }
                if (a == 2 && b == 2) {
                    cntEqual -= (s1[pos1] == s2[pos1]);
                    cntEqual -= (s1[pos2] == s2[pos2]);
                    swap(s2[pos1], s2[pos2]);
                    cntEqual += (s1[pos1] == s2[pos1]);
                    cntEqual += (s1[pos2] == s2[pos2]);
                }
                if (a == 1 && b == 2) {
                    cntEqual -= (s1[pos1] == s2[pos1]);
                    cntEqual -= (s1[pos2] == s2[pos2]);
                    swap(s1[pos1], s2[pos2]);
                    cntEqual += (s1[pos1] == s2[pos1]);
                    cntEqual += (s1[pos2] == s2[pos2]);
                }
                if (a == 2 && b == 1) {
                    cntEqual -= (s1[pos1] == s2[pos1]);
                    cntEqual -= (s1[pos2] == s2[pos2]);
                    swap(s2[pos1], s1[pos2]);
                    cntEqual += (s1[pos1] == s2[pos1]);
                    cntEqual += (s1[pos2] == s2[pos2]);
                }
            } else if (type == 3) {
                cout << (cntEqual == n - blocked.size() ? "YES" : "NO") << '\n';
            }
        }
    }
}