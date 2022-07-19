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

    int n, m, p;
    cin >> n >> m >> p;

    int dist[n][m];
    memset(dist, OO, sizeof dist);

    pair<int, int> goal;

    vector<pair<int, int>> chests[p + 1];
    vector<int> indices[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            chests[c].push_back({i, j});
            if (c == 1) {
                dist[i][j] = i + j;
                indices[i].push_back(j);
            } else if (c == p)
                goal = {i, j};
        }
    }


    for (int chest = 2; chest <= p; chest++) {
        for (auto[row, col]: chests[chest]) {
            for (int i = 0, j; i < n; i++) {
                auto it = lower_bound(indices[i].begin(), indices[i].end(), col);
                if (it != indices[i].end()) {
                    j = *it;
                    dist[row][col] = min(dist[row][col], abs(row - i) + abs(col - j) + dist[i][j]);
                }
                it = upper_bound(indices[i].begin(), indices[i].end(), col);
                if (it != indices[i].begin()) {
                    it--;
                    j = *it;
                    dist[row][col] = min(dist[row][col], abs(row - i) + abs(col - j) + dist[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
            indices[i].clear();

        for (auto[row, col]: chests[chest])
            indices[row].push_back(col);
    }

    cout << dist[goal.first][goal.second];
}