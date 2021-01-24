#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<bool> isPrime(N, true);
vector<int> primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    /* This loop could be optimized */
    for(int i = 2; i < N; i++) {
        if (isPrime[i]) {

            /* Keep it only if you need it */
            primes.push_back(i);

            /* This loop could be optimized */
            for (int j = i; j < N; j += i) {
                if(j != i)
                    isPrime[j] = false;
            }
        }
    }
}

int freq[30];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve();

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    vector<pair<int, char>> v;
    for (int i = 0; i < 30; i++)
        if (freq[i])
            v.push_back({freq[i], char('a' + i)});

    sort(v.begin(), v.end());

    string nxt = "";
    for (auto &p : v)
        while (p.first > 0) {
            nxt += p.second;
            p.first--;
        }

    string t(n, '?');
    for (auto p : primes) {
        if (p - 1 >= n) break;
        for (int i = p - 1; i < n; i += p) {
            if (s.empty()) break;
            char c = nxt.back();
            if (t[i] != '?') continue;
            t[i] = c;
            nxt.pop_back();
        }
    }


    for (auto p : primes) {
        if (p - 1 >= n) break;
        char c = t[p - 1];
        for (int i = p - 1; i < n; i += p) {
            if (t[i] != c || t[i] == '?') return cout << "NO", 0;
        }
    }


    cout << "YES\n";
    t[0] = nxt.back();

    cout << t;
}