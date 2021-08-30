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

    string a, b;    cin >> a >> b;

    int ans = 0;
    for(int i = 0;i < n / 2;i++){
        int freq[26] = {0};

        freq[a[i] - 'a']++;
        freq[a[n - i - 1] - 'a']++;

        freq[b[i] - 'a']++;
        freq[b[n - i - 1] - 'a']++;

        int cnt = 0;
        for(int j = 0;j < 26;j++)
            cnt += freq[j] > 0;


        if(cnt == 2) {
            if(a[i] == a[n - i - 1]) {
                if(freq[a[i] - 'a'] == 2)
                    ans += 0;
                else if(freq[a[i] - 'a'] == 3)
                    ans++;
            }
            else{
                if(b[i] != b[n - i - 1])
                    ans += 0;
                else ans++;
            }
        }
        else if(cnt == 3){
            if(a[i] == a[n - i - 1])    ans += 2;
            else ans += 1;
        }
        else if(cnt == 4)
            ans += 2;
    }

    if(n & 1)
        ans += a[n / 2] != b[n / 2];

    cout << ans;
}