#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    ll a, b, c, d;  cin >> a >> b >> c >> d;

    auto solve = [&](ll n){
        return n - ((n / c) + (n / d) - (n / lcm(c, d)));
    };

    cout << solve(b) - solve(a - 1);
}