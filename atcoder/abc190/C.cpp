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

    int n, m;   cin >> n >> m;

    int a[m], b[m];
    for(int i = 0;i < m;i++)
        cin >> a[i] >> b[i];


    int k;  cin >> k;

    int c[k], d[k];
    for(int i = 0;i < k;i++)
        cin >> c[i] >> d[i];

    int freq[n + 1] = {0}, ans = 0;
    for(int i = 0;i < (1 << k);i++){
        memset(freq, 0, sizeof freq);
        for(int j = 0;j < k;j++){
            if((i >> j) & 1)
                freq[c[j]]++;
            else
                freq[d[j]]++;
        }

        int cnt = 0;
        for(int j = 0;j < m;j++) {
            if (freq[a[j]] && freq[b[j]])
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}