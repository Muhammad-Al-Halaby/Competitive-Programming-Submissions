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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    ll k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;

    ll ans = 0;
    ll mn = min({k2, k5, k6});
    ans += mn * 256;
    k2 -= mn;
    ans += 32 * min({k2, k3});

    cout << ans;
}