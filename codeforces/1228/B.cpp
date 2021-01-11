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

const int N = 1e3 + 5, M = 600, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}

int grid[N][N];
int main(){
    init();


    int n, m;   cin >> n >> m;
    memset(grid, -1, sizeof grid);
    for(int i = 0;i < n;i++){
        int r;  cin >> r;
        for(int j = 0;j < r;j++)    grid[i][j] = 1;
        if(r < m)
            grid[i][r] = 0;
    }

    for(int i = 0;i < m;i++){
        int c;  cin >> c;
        for(int j = 0;j < c;j++)    {
            if(grid[j][i] == 0)
                return cout << 0, 0;
            grid[j][i] = 1;
        }
        if(c < n){
            if(grid[c][i] == 1)
                return cout << 0, 0;
            grid[c][i] = 0;
        }
    }

    int cnt = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cnt += (grid[i][j] == -1);
    cout << power(2, cnt);
}