#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll calcDist(int x, int y, int a, int b){
    return 1ll * abs(x - a) + abs(y - b);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;

        ll d1 = calcDist(x, y, 1, 1) + calcDist(1, 1, n, m) + calcDist(n, m, x, y);
        ll d2 = calcDist(x, y, 1, m) + calcDist(1, m, n, 1) + calcDist(n, 1, x, y);

//        {{1, 1}, {n, m}}
//        {{1, m}, {n, 1}}

        if(d1 >= d2)
            cout << 1 << " " << 1 << " " << n << " " << m << '\n';
        else
            cout << 1 << " " << m << " " << n << " " << 1 << '\n';

    }

}