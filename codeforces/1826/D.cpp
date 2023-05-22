#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, OO = 0x3f3f3f3f;

int n, a[N];
int dp[N][3];

int solve() {
    dp[0][0] = a[0] + 1;
    dp[0][1] = a[0];
    dp[0][2] = -OO;

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], a[i] + (i + 1));
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + a[i] - (i + 1));
    }

    return dp[n - 1][2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve() << '\n';
    }

    return 0;
}