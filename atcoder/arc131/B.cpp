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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] != '.') {
                continue;
            }
            set<char> colors = {'1', '2', '3', '4', '5'};
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= h) {
                    continue;
                }
                if (nj < 0 || nj >= w) {
                    continue;
                }
                if (colors.count(g[ni][nj])) {
                    colors.erase(g[ni][nj]);
                }
            }
            g[i][j] = *colors.begin();
        }
    }
    for (int i = 0; i < h; ++i) {
        cout << g[i] << "\n";
    }
}