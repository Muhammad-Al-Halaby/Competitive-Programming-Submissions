#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;    cin >> n >> m;

    if(m == 0)
        return cout << 1, 0;

    map<ll, int> mp;

    vector<ll> cells(m + 2);
    cells[0] = 0;
    for(int i = 1;i <= m;i++) {
        cin >> cells[i];
        mp[cells[i]] = 1;
    }
    cells[m + 1] = n;

    sort(cells.begin(), cells.end());

    ll len = llOO;
    for(int i = 1;i <= m + 1;i++) {
        ll x = cells[i] - cells[i - 1] - mp[cells[i]];
        if(x <= 0)    continue;
        len = min(len, x);
    }

    ll ans = 0;
    for(int i = 1;i <= m + 1;i++) {
        ll x = cells[i] - cells[i - 1] - mp[cells[i]];
        if(x <= 0)    continue;
        ans += ceil(1.0 * x / len);
    }

    cout << ans;
}