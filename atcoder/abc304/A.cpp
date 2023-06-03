#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    string s[n];
    int a[n];
    int mn = 0;
    for(int i = 0;i < n;i++){
        cin >> s[i] >> a[i];
        if(a[mn] >= a[i])
            mn = i;
    }

    for(int i = mn;i < n;i++){
        cout << s[i] << '\n';
    }

    for(int i = 0;i < mn;i++){
        cout << s[i] << '\n';
    }


}