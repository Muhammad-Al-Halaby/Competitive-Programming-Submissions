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

    int n;  cin >> n;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    int b[5];
    for(int i = 0;i < 5;i++)    cin >> b[i];

    ll points = 0, freq[5] = {0};
    for(int i = 0;i < n;i++){
        points += a[i];
        for(int j = 4;j >= 0;j--) {
            ll cnt = points / b[j];
            points -= cnt * b[j];
            freq[j] += cnt;
        }
    }

    for(int i = 0;i < 5;i++)
        cout << freq[i] << "\n "[i + 1 < 5];
    
    cout << points;
}