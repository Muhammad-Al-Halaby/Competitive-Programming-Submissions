#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;   cin >> n >> x;
    string s;   cin >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == 'o') x++;
        else x = max(x - 1, 0);
    }

    cout << x;
}