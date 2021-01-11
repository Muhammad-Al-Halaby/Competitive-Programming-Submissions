#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    double a, b, h, m; cin >> a >> b >> h >> m;

    h = h * 5;

    double d = (h * 6) - (m * 6) + (30 * m / 60);

    d = d * acos(-1) / 180.0;

    double x = cos(d);

    double ans = sqrt((a * a) + (b * b) - 2.0 * a * b * x);

    cout << fixed << setprecision(20) << ans;
}