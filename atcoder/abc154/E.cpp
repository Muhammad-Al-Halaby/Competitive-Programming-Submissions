#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 105, M = 105, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


string n;
int k;
ll dp[N][4][2];

ll solve(int i, int nonzero, bool ok){
    if(i == n.size())   return nonzero == k;
    if(nonzero > k) return 0;

    ll &ret = dp[i][nonzero][ok];
    if(~ret)    return ret;

    int lastDigit = n[i] - '0';
    if(ok){
        ret = solve(i + 1, nonzero, ok) + 9 * solve(i + 1, nonzero + 1, ok);
    }
    else{
        ret = solve(i + 1, nonzero, 0 < lastDigit);
        if(lastDigit > 0)
            ret += solve(i + 1, nonzero + 1, ok) + (lastDigit - 1) * solve(i + 1, nonzero + 1, 1);
    }

    return ret;
}
int main(){
    init();
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    cout << solve(0, 0, 0);
}