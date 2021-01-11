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

const int N = 5005;
int n, dp[N][N];
string s;

int solve(int i = 0, int j = n - 1){
  	if(i > j)
      return 1;

    if(i == j)
        return dp[i][j] = 1;

    int &ret = dp[i][j];
    if(~ret)	return ret;

  	ret = 0;

	solve(i + 1, j);
	solve(i, j - 1);

  	return ret |= s[i] == s[j] && solve(i + 1, j - 1);
}

int calc(int l, int r){
	return dp[r][r] - (l == 0 ? 0 : dp[l-1][r]) - (l == 0 ? 0 : dp[r][l-1]) + (l == 0 ? 0 : dp[l-1][l-1]);
}

int main(){
  init();

  cin >> s;
  n = s.size();

  memset(dp, -1, sizeof dp);
  solve(0, n - 1);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(dp[i][j] == -1)
        dp[i][j] = 0;
	      dp[i][j] += (j == 0 ? 0 : dp[i][j-1]);
    }
  }

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
	      dp[i][j] += (i == 0 ? 0 : dp[i-1][j]);
    }
  }

  int q;	cin >> q;
  for(int i = 0;i < q;i++){
    int l, r;	cin >> l >> r;	--l, --r;
  	cout << calc(l,r) << '\n';
  }
}
