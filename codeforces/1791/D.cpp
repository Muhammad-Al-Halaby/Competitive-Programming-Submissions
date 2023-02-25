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
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int freq[26] = {0};
        int freq2[26] = {0};

        int f1 = 1, f2 = 0;
        freq[s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            freq2[s[i] - 'a']++;
            if (freq2[s[i] - 'a'] == 1)
                f2++;
        }

        int ans = f1 + f2;
        for (int i = 1; i < n; i++) {
            freq2[s[i] - 'a']--;
            if (freq2[s[i] - 'a'] == 0)
                f2--;

            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 1)
                f1++;

            ans = max(ans, f1 + f2);
        }

        cout << ans << '\n';
    }
}