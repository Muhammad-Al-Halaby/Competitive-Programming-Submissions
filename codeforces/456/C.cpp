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

int n, fr[N], ok[N], arr[N];

ll dp[N][2];
ll solve(int i){
    if(i == n)
        return 0;

    ll v = arr[i];

    ll &res = dp[i][bool(ok[v])];
    if(~res)
        return res;

    res = solve(i + 1);

    if(ok[v]){
        ok[v - 1] = 0;
        ok[v + 1] = 0;

        res = max(res, v * fr[v] + solve(i + 1));

        ok[v - 1] = 1;
        ok[v + 1] = 1;
    }

    return res;
}
int main(){
    init();
    cin >> n;
    set<int> s;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        fr[x]++;
        s.insert(x);
    }

    n = s.size();
    int i = 0;
    for(auto v : s){
        arr[i++] = v;
    }

    memset(dp, -1, sizeof dp);
    memset(ok, true, sizeof ok);

    cout << solve(0);
}