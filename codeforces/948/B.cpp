#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<bool> isPrime(N, true);
vector<int> largestPrimeFactor(N, 1);

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
                largestPrimeFactor[j] = i;
           }
        }
    }
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve();

    int x2; cin >> x2;

    int x0 = OO;
    for(int x1 = x2 - largestPrimeFactor[x2] + 1;x1 <= x2;x1++){
        if(isPrime[x1])  continue;
        x0 = min(x0, x1 - largestPrimeFactor[x1] + 1);
    }

    cout << x0;
}