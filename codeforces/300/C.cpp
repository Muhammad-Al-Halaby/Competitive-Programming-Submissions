#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
//    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e7, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int a, b, n;

inline bool good(int x){
    int ret = true;
    while(x){
        int ld = x % 10;
        ret &= ((ld == a) || (ld == b));
        x /= 10;
    }
    return ret;
}


inline ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}


ll numerator = 1, denominator[N];
inline int perm(int r1, int r2){
    return numerator * ((denominator[r1] * denominator[r2]) % modulo) % modulo;
}

int main(){
    init();

    cin >> a >> b >> n;

    for(int i = 1;i <= n;i++){
        numerator *= i;
        if(numerator >= modulo) numerator %= modulo;
    }

    denominator[0] = denominator[1] = 1;
    for(int i = 2; i <= n; i++)
        denominator[i] = denominator[modulo % i] * (modulo - modulo / i) % modulo;

    for(int i = 2; i <= n; i++)
        denominator[i] = (denominator[i] * denominator[i - 1]) % modulo;

    ll ans = 0;
    for(int i = 1;i <= max(a, b) * n;i++){
        if(good(i)){
            int s = i;
            for(int cnta = 0;cnta * a <= s;cnta++){
                if((s - a * cnta) % b) continue;
                int cntb = (s - a * cnta) / b;
                if(cnta + cntb == n){
                    ans += perm(cnta, cntb);
                    if(ans >= modulo)   ans %= modulo;
                }
            }
        }
    }

    cout << ans;
}
