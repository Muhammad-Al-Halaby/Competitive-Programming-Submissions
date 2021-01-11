#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;   cin >> s;
    int cnt = 0;

    ll ans = 1;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'b')
            ans = (ans * (cnt + 1)) % modulo, cnt = 0;
        else if(s[i] == 'a') cnt++;
    }

    ans = (ans * (cnt + 1)) % modulo;

    cout << ans - 1;
}