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

const int N = 1e6 + 9;

ll n, x;
ll dp[N][4];
int arr[N];

ll solve(int i, int state){
    if(i == n || state == 4)
        return 0;

    ll &res = dp[i][state];
    if(~res)    return res;

    if(state == 0){
        res = solve(i + 1, state);
    }
    else if(state == 1 || state == 3){
        res = arr[i] + solve(i + 1, state);
    }
    else if(state == 2){
        res = arr[i] * x + solve(i + 1, state);
    }

    return res = max(res, solve(i, state + 1));
}

int main(){
    init();

    memset(dp, -1, sizeof dp);

    cin >> n >> x;
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    cout << solve(0, 0);
}