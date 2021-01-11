#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << min({a, b, c, d});

}