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

const int N = 55, OO = 0x3f3f3f;
int n, m;

ll dp[N][N][N];

int cost[N][3];

ll solve(int i, int j, int k){
    if(i == n || j == n || k == n)
        return OO;

    ll &ret = dp[i][j][k];
    if(~ret)    return ret;

    ret = OO;

    if(i != j && j != k && i != k)
        ret = (ll)cost[i][0] + cost[j][1] + cost[k][2];

    return ret = min(ret, min(solve(i + 1,j, k), min(solve(i, j + 1, k), solve(i, j, k + 1))));
}

int main(){
    init();

    memset(dp, -1, sizeof dp);
    memset(cost, OO, sizeof cost);

    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string s;   cin >> s;
        for(int j = 0;j < m;j++){
            if(isdigit(s[j]))
                cost[i][0] = min(cost[i][0], min(j, m - j));
            else if(isalpha(s[j]))
                cost[i][1] = min(cost[i][1], min(j, m - j));
            else
                cost[i][2] = min(cost[i][2], min(j, m - j));
        }
    }

    cout << solve(0, 0, 0);
}