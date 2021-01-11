#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

typedef vector<ll> row;
typedef vector<row> matrix;

matrix zero(int n, int m){
    return matrix(n, row(m, 0));
}

matrix identity(int n){
    matrix ret = zero(n, n);
    for(int i = 0;i < n;i++)    ret[i][i] = 1;
    return ret;
}

matrix multiply(const matrix &a, const matrix &b){
    matrix ret = zero(a.size(), b[0].size());
    for(int i = 0;i < a.size();i++){
        for(int k = 0;k < a[0].size();k++){
            for(int j = 0;j < b[0].size();j++){
                ret[i][j] += (a[i][k] * b[k][j]) % modulo;
                ret[i][j] %= modulo;
            }
        }
    }
    return ret;
}

matrix power(const matrix &a, ll k){
    if(k == 0)
        return identity(a.size());

    if(k % 2 == 1)
        return multiply(a, power(a, k - 1));

    return power(multiply(a, a), k / 2);
}

ll power(ll b, ll p, ll mod = 2e18){
    if(p == 0)return 1;
    ll res = power(b,p/2, mod);
    res *= res;
    res %= mod;
    if(p & 1)res *= b;
    return res % mod;
}

int main() {
    init();

    int n;  cin >> n;

    int a[10][10] = {};
    for(int i = 1;i <= n;i++){
        string s = to_string(i);
        a[s[0] - '0'][s.back() - '0']++;
    }

    ll ans = 0;
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            ans += a[i][j] * a[j][i];
        }
    }
    
    cout << ans;
}