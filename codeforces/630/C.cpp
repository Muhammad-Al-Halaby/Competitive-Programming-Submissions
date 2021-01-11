#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;  cin >> n;

    cout << (1ll << (n + 1)) - 2;
}