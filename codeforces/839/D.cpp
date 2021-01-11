#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

ll freq[N], ans[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        for(int j = 1;j * j <= a[i];j++){
            if(a[i] % j)    continue;
            freq[j]++;
            if(a[i] / j != j) {
                freq[a[i] / j]++;
            }
        }
    }

    for(int i = N-1;i >= 2;i--){
//        1 nCk(n, 1) + 2 * nCk(n, 2) + .... + n * nCk(n, n) = n * power(2, n - 1);
//        ans[2] = freq[2] * power(2, freq[2] - 1) - ans of all multiples (inclusion-exclusion)
        ans[i] = freq[i] * power(2, freq[i] - 1, modulo);
        ans[i] %= modulo;
        for(int j = i * 2;j < N;j += i){
            ans[i] -= ans[j];
            ans[i] += modulo;
            ans[i] %= modulo;
        }
    }

    ll finalAns = 0;
    for(int i = 2;i < N;i++){
        finalAns += i * ans[i];
        finalAns %= modulo;
    }

    cout << finalAns;
}