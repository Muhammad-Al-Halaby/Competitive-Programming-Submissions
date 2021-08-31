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

    int n, sz;  cin >> n >> sz;

    sz *= 8;

    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int k = sz / n;
    int distinct = 1 << min(20, k);

    sort(a, a + n);

    map<int, int> mp;

    int ans = OO, cnt = 0;
    for(int l = 0, r = 0;l < n;l++){

        while(r < n && cnt <= distinct){
            ans = min(ans, l + n - r);

            if(mp[a[r]] == 0){
                if(cnt + 1 > distinct)  break;
                cnt++;
            }

            mp[a[r]]++;
            r++;
        }

        if(cnt <= distinct)
            ans = min(ans, l + n - r);

        mp[a[l]]--;
        if(mp[a[l]] == 0)   cnt--;
    }

    cout << (distinct == n ? 0 : ans);
}