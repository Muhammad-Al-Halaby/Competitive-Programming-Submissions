#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>> divisors(N);

void getDivisors(ll n) {
    if(divisors[n].size())  return;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors[n].push_back(i);
            if (n / i != i)
                divisors[n].push_back(n / i);
        }
    }

    sort(divisors[n].rbegin(), divisors[n].rend());
}

ll ans[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;  cin >> n;
    ans[0] = 1;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        getDivisors(x);
        for(auto d : divisors[x]){
            ans[d] += ans[d - 1];
            ans[d] %= modulo;
        }
    }

    ll res = 0;
    for(int i = 1;i < N;i++) {
        res += ans[i];
        res %= modulo;
    }

    cout << res;
}