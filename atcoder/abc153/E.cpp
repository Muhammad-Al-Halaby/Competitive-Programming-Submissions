#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 1e3 + 9, M = 1e4 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, a[N], b[N], dp[N][M];

int solve(int i, int rem){
    if(rem <= 0)    return 0;
    if(i == n)  return ((rem <= 0) ? 0 : OO);

    int &ret = dp[i][rem];
    if(~ret)    return ret;

    ret = min(solve(i, rem - a[i]) + b[i], solve(i + 1, rem));

    return ret;
}

int main(){
    init();

    int h;  cin >> h >> n;
    for(int i = 0;i < n;i++) cin >> a[i] >> b[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, h);
}
