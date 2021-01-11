#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;


int q, j, r[N], vis[N][2], vid;
double dp[N][2], p[N];

double solve(int i, bool sorted){
    if(sorted)  return 1;
    if(i == q)  return 0;

    double &ret = dp[i][sorted];

    if(vis[i][sorted] == vid)   return ret;

    vis[i][sorted] = vid;

    double doit = p[i] * solve(i + 1, r[i] >= j);
    double dont = (1 - p[i]) * solve(i + 1, sorted);

    return  ret = doit + dont;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n >> q;
        int a[n];
        for(int i = 0;i < n;i++)
            cin >> a[i];

        j = n - 1;
        while(j >= 0 && a[j] == j + 1)j--;


        for(int i = 0;i < q;i++) {
            cin >> r[i] >> p[i];
            r[i]--;
        }

        vid++;
        cout << fixed << setprecision(10) << solve(0, j == -1) << '\n';
    }
}