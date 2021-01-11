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

const int N = 205, M = 5e4 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, k, t[N], f[N];
int dp[N][6000];

int main(){
    init();

    cin >> n >> k;
    for(int i = 0;i < n;i++){
        ll x;  cin >> x;

        while(x % 2 == 0){
            t[i]++; x /= 2;
        }

        while(x % 5 == 0){
            f[i]++; x /= 5;
        }

    }

    memset(dp, -1, sizeof dp);

    dp[k][0] = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int rem = 1;rem <= k;rem++){
            for(int fives = 0;fives < 6000;fives++){
                if(dp[rem][fives] != -1){
                    int twos = dp[rem][fives];
                    int &curr = dp[rem - 1][fives + f[i]];
                    curr = max(curr, t[i] + twos);
                    ans = max(ans, min(fives + f[i], curr));
                }
            }
        }
    }

    cout << ans;
}