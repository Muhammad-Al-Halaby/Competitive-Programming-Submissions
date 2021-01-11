#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, t;    cin >> n >> m >> t;

    int nn = n, b = 0;
    for(int i = 0;i < m;i++){
        int x, y;   cin >> x >> y;
        nn -= (x - b);
        nn = max(0, nn);
        if(!nn) return cout << "No", 0;
        nn = min(n, nn + (y - x));
        b = y;
    }

    nn -= t - b;
    nn = max(0, nn);

    if(nn)
        cout << "Yes";
    else
        cout << "No";
}