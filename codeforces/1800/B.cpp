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

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int small[26] = {0};
        int cap[26] = {0};
        for(int i = 0;i < s.size();i++){
            if(s[i] == tolower(s[i]))   small[s[i] - 'a']++;
            else  cap[s[i] - 'A']++;
        }

        int ans = 0;
        for(int i = 0;i < 26;i++){
            ans += min(small[i], cap[i]);
            int diff = abs(small[i] - cap[i]);
            ans += min(k, diff / 2);
            k -= min(k, diff / 2);
        }

        cout << ans << '\n';
    }
}