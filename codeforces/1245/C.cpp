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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 3e5 + 5, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n;
string s;
ll dp[N];

ll solve(int i, int prev = 0){
    if(i == n)  return 1;

    ll &ret = dp[i];
    if(~ret)    return ret;

    ret = solve(i + 1);
    if(i + 1 < n && ((s[i] == 'u' && s[i+1] == 'u') || (s[i] == 'n' && s[i+1] == 'n')))
        ret += solve(i + 2, i);

    while(ret >= modulo)    ret -= modulo;

    return ret;
}

int main(){
    init();
    memset(dp, -1, sizeof dp);

    cin >> s;   n = s.size();

    for(int i = 0;i < n;i++)
        if(s[i] == 'm' || s[i] == 'w')
            return cout << 0, 0;

    cout << solve(0);

}