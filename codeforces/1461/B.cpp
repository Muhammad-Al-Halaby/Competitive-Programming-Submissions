#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        char grid[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        int prefix[n][m] = {};
        int suffix[n][m] = {};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') continue;

                if (j)
                    prefix[i][j] = (grid[i][j - 1] == '*') + prefix[i][j - 1];

            }
        }



        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == '.') continue;

                if (j + 1 < m)
                    suffix[i][j] = (grid[i][j + 1] == '*') + suffix[i][j + 1];
            }
        }


        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k + i < n; k++) {
                    if (grid[i + k][j] == '*' && prefix[i + k][j] >= k && suffix[i + k][j] >= k) {
                        ans++;
                    }
                    else
                        break;
                }
            }
        }

        cout << ans << '\n';
    }
}