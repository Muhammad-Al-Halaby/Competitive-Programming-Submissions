#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 20 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    if(p & 1)res *= b;
    return res;
}

ll freq1[N], freq2[N], freq[N];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;


    for (int i = 0; i < s.size() - 1; i++) {
        freq1[s[i] - '0']++;
        freq[s[i] - '0']++;
    }

    for (int i = 0; i < t.size() - 1; i++) {
        freq2[t[i] - '0']++;
        freq[t[i] - '0']++;
    }

    ll score1 = 0, score2 = 0;
    for (int i = 1; i <= 9; i++) {
        score1 += i * power(10, freq1[i]);
        score2 += i * power(10, freq2[i]);
    }


    ll total = 0, cnt = 0;

    for (ll i = 1; i <= 9; i++) {
        for (ll j = 1; j <= 9; j++) {
            if (i == j) {
                ll rem = k - freq[i];
                total += rem * (rem - 1);
            } else {
                total += (k - freq[i]) * (k - freq[j]);
            }
        }
    }


    for (ll i = 1; i <= 9; i++) {
        for (ll j = 1; j <= 9; j++) {
            if(i == j) {
                if (k - freq[i] < 2) continue;
            }
            else if(k - freq[i] < 1 || k - freq[j] < 1) continue;

            ll newScore1 = score1 + (freq1[i] ? i * 9 * power(10, freq1[i]) : i * 9);
            ll newScore2 = score2 + (freq2[j] ? j * 9 * power(10, freq2[j]) : j * 9);
            if (newScore1 > newScore2) {
                if (i == j) {
                    ll rem = k - freq[i];
                    cnt += rem * (rem - 1);
                } else {
                    cnt += (k - freq[i]) * (k - freq[j]);
                }
            }
        }
    }

    cout << fixed << setprecision(12) << (1.0 * cnt / total);
}