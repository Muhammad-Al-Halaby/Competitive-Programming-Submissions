#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 5e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<bool> isPrime(N, true);
vector<ll> factorsCount(N, 0);

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    /* This loop could be optimized */
    for(int i = 2; i < N; i++) {
        if (isPrime[i]) {

            /* This loop could be optimized */
            for (int j = i; j < N; j += i) {
                if(j != i)
                    isPrime[j] = false;

                /* Keep it only if you need it */
                int cpy = j, cnt = 0;
                while (cpy % i == 0) cpy /= i, cnt++;

                factorsCount[j] += cnt;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve();
    for(int i = 3;i < N;i++)
        factorsCount[i] += factorsCount[i - 1];

    int t;  cin >> t;
    while(t--){
        int a, b;   cin >> a >> b;
        cout << factorsCount[a] - factorsCount[b] << '\n';
    }
}