#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        string s = "abc";
        for (int i = 0; i < n; i++) {
            cout << s[i % 3];
        }
        cout << '\n';
    }
}