#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e7 + 9, M = 1e7 + 9, OO = 0x3f3f3f3f;
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
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve();
    
    int t;  cin >> t;
    while(t--){
        int d;  cin >> d;
        int x = *lower_bound(primes.begin(), primes.end(), 1 + d);
        int y = *lower_bound(primes.begin(), primes.end(), x + d);
        cout << 1ll * x * y << '\n';
    }
}