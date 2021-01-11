#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, sum, ones[N], ans;

string s;

int dp[N][3];

int solve(int i, int stage){
    if(stage == 3)  return OO;
    if(i >= n)  return 0;

    int &ret = dp[i][stage];
    if(~ret)    return ret;

    ret = OO;

    int val = s[i] - '0';
    ret = min(ret, (stage != 1 ? val : !val) + solve(i + k, stage));
    ret = min(ret, solve(i, stage + 1));

    return ret;
}


int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;

        memset(ones, 0, n * sizeof ones[0]);
        memset(dp, -1, n * 3 * sizeof dp[0][0]);

        sum = count(s.begin(), s.end(), '1');
        for(int i = 0;i < n;i++)    ones[i % k] += (s[i] == '1');

        ans = OO;
        for(int i = 0;i < k;i++)
            ans = min(ans, solve(i, 0) + sum - ones[i]);

        cout << ans << '\n';
    }
}