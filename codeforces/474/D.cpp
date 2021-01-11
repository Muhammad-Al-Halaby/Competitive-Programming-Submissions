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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 1e5 + 5;
ll dp[N];
int n, k;
ll solve(int len){
    if(len == 0)
        return 1;

    ll &res = dp[len];
    if(~res)
        return res;

    res = 0;
    if(len >= k)
        res += solve(len - k);
    res += solve(len - 1);

    res %= modulo;

    return res;
}
int main(){
    init();
    memset(dp, -1, sizeof dp);

    cin >> n >> k;

    solve(1e5+1);

    for(int i = 1;i < N;i++){
        dp[i] += dp[i - 1];
        dp[i] %= modulo;
    }

    for(int i = 0;i < n;i++){
        int a, b;   cin >> a >> b;
        cout << ((dp[b] - dp[a - 1]) + modulo) % modulo << '\n';
    }
}