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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 2e3 + 9, M = 1e5 + 9;
int n, h, l, r, a[N], dp[N][N];

bool in_range(int x){
    return x >= l && x <= r;
}
int solve(int i, int t){
    if(i == n)  return 0;

    int &ret = dp[i][t];
    if(~ret)    return ret;

    ret = in_range((t + a[i]) % h) + solve(i + 1, (t + a[i] + h) % h);
    ret = max(ret, in_range((t + a[i] - 1) % h) + solve(i + 1, (t + a[i] - 1 + h) % h));

    return ret;
}

int main(){
    init();

    cin >> n >> h >> l >> r;
    for(int i = 0;i < n;i++)    cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
}
