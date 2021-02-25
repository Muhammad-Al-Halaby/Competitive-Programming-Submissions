#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
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
                if (j != i)
                    isPrime[j] = false;
            }
        }
    }
}

map<int, int> dp;

int grundy(int mask){
    if(dp.count(mask))  return dp[mask];

    int &ret = dp[mask] = 0;

    set<int> states;

    int cnt = __builtin_popcount(mask);
    for(int i = 0;cnt;i++){
        cnt -= (mask >> i) & 1;

        int shifted_mask = (mask >> (i + 1)) | (mask & ((1 << i) - 1));

        states.insert(grundy(shifted_mask));
    }

    int grundy_num = 0;
    while(states.count(grundy_num))
        grundy_num++;

    return ret = grundy_num;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve();

    int n;  cin >> n;

    map<int, int> mask;

    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        for(auto p : primes){
            int cnt = 0;
            while(x % p == 0)
                x /= p, cnt++;
            if(cnt) {
                if(mask.count(p) == 0)  mask[p] = 0;
                mask[p] |= (1 << (cnt - 1));
            }
        }
        if(x > 1)
            mask[x] |= 1;
    }

    int state = 0;
    for(auto p : mask){
        state ^= grundy(p.second);
    }

    if(state)
        cout << "Mojtaba";
    else
        cout << "Arpa";
}