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

    int n, m;
    cin >> n >> m;

    int a[n];
    map<pair<int, int>, int> good;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> a[j];
            if(j) {
                good[{a[j], a[j - 1]}] = 1;
                good[{a[j - 1], a[j]}] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++) {
        for (int j = i + 1; j < n; j++) {
            if(good.count({i + 1, j + 1}) == 0) {
                ans++;
            }
        }
    }

    cout << ans;
}