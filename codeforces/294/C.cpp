#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p, ll mod = 2e18){
    if(p <= 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

ll inverse(ll n){
    return power(n, modulo - 2, modulo);
}

ll factorial[N], inv[N];

int main() {

    factorial[0] = 1;
    inv[0] = inverse(1);
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % modulo;
        inv[i] = inverse(factorial[i]);
    }

    int n, m;   cin >> n >> m;

    int a[m];
    for(int i = 0;i < m;i++)    cin >> a[i];
    sort(a, a + m);

    /*
        2 cases:
            1000000 | 000001 = 1
            100001 = 2^(n-1) where n = length of zeros
    
        ans = ways of combining different cases * ways to solve each case
    */

    ll sum = (a[0] - 1) + (n - a[m - 1]), repeated = (inv[a[0] - 1] * inv[n - a[m - 1]]) % modulo, blocks_choices = 1;
    for(int i = 1;i < m;i++){
        int len = a[i] - a[i - 1] - 1;

        sum += len;

        repeated *= inv[len];
        repeated %= modulo;

        blocks_choices *= power(2, len - 1, modulo);
        blocks_choices %= modulo;
    }


    cout << (((factorial[sum] * repeated) % modulo) * blocks_choices) % modulo;
}
