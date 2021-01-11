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

const int N = 1e3 + 5, OO = 0x3f3f3f;

int n, zeros, zi, zj;

int grid[N][N][2];

int dp[N][N][2];

int cntFactor(int n, int f){
    int res = 0;
    while(n != 0 && n % f == 0){
        res++;
        n /= f;
    }
    return res;
}

int solve(int i, int j, int mode){
    if(i == n && j == n - 1)
        return 0;
    if(i == n || j == n)
        return 1e9;

    int& res = dp[i][j][mode];
    if(~res)    return res;

    return res = grid[i][j][mode] + min(solve(i + 1, j, mode), solve(i, j + 1, mode));
}

void print(){
    for(int i = 0;i < zj;i++)
        cout << "R";
    for(int i = 0;i < n - 1;i++)
        cout << "D";
    for(int i = zj;i < n - 1;i++)
        cout << "R";
}

void print(int i, int j, int mode){
    if(i == n - 1 && j == n - 1)
        return;

    int current = solve(i, j, mode);
    if(current == grid[i][j][mode] + solve(i + 1, j, mode)){
        cout << 'D';
        print(i + 1, j, mode);
    }
    else{
        cout << 'R';
        print(i, j + 1, mode);
    }
}

int main(){
    init();

    memset(dp, -1, sizeof dp);

    cin >> n;

    zi = zj = -1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int x;  cin >> x;
            grid[i][j][0] = cntFactor(x, 2);
            grid[i][j][1] = cntFactor(x, 5);
            if(x == 0)
                zi = i, zj = j;
        }
    }

    int ans = min(solve(0, 0, 0), solve(0, 0, 1));
    if(ans > 1 && ~zi){
        cout << 1 << '\n';
        print();
        return 0;
    }

    cout << ans << '\n';
    print(0, 0, !(solve(0, 0, 0) < solve(0, 0, 1)));
}
