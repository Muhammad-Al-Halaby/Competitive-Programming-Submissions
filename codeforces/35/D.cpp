#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge

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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 105, X = 5e4, OO = 0x3f3f3f3f;
int n, x, c[N];

int dp[N][X];

int solve(int i, int total){
    if(total < 0)
        return -OO;
    if(i == n)
        return 0;

    int &ret = dp[i][total];

    if(~ret)    return ret;

    return ret = max(solve(i + 1, total), 1 + solve(i + 1, total - (n - i) * c[i]));
}
int main(){
    init();

    memset(dp, -1, sizeof dp);

    cin >> n >> x;
    for(int i = 0;i < n;i++)
        cin >> c[i];

    cout << solve(0, x);
}