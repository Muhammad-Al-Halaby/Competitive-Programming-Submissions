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
#define modulo ll (998244353)//(1e9 + 7)
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

const int N = 105, M = 1e6 + 6, OO = 0x3f3f3f3f;

string s;

int power10[] = {1, 10, 100};

int dp[N][8][4];
vector<int> ans;

int solve(int i, int m, int pos){
    if(m == 0 && pos > 0){
        cout << "YES\n";
        for(int i = ans.size() - 1; ~i ; i--)   cout << ans[i];
        exit(0);
    }

    if(i == s.size() || pos == 3)    return 0;

    int &ret = dp[i][m][pos];
    if(~ret)    return ret;

    int d = s[i] - '0';

    ret = solve(i + 1, m, pos);

    ans.push_back(d);
    ret = solve(i + 1, (m + d * power10[pos]) % 8, pos + 1);
    ans.pop_back();
}

int main(){
    init();

    cin >> s;
    reverse(s.begin(), s.end());
    memset(dp, -1, sizeof dp);
    solve(0, 0, 0);
    cout << "NO";
}