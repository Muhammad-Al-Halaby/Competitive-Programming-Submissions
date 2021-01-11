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

const int N = 105, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int n, t[N], w[N], dp[N][2 * N];

int solve(int i, int rem){
    if(i == n)  return ((rem == 0) ? 0 : -1e5);
    if(rem < 0) return -1e5;

    int &ret = dp[i][rem];
    if(~ret)    return ret;

    return ret = max(solve(i + 1, rem - t[i]) + w[i], solve(i + 1, rem));
}

int main(){
    init();

    memset(dp, -1, sizeof dp);

    cin >> n;
    for(int i = 0;i < n;i++)    cin >> t[i] >> w[i];

    int totalThin = accumulate(t, t + n, 0);
    int totalWidth = accumulate(w, w + n, 0);
    int ans = OO;
    for(int i = 1;i <= totalThin;i++){
        if(totalWidth - solve(0, i) <= i) return cout << i, 0;
    }
}