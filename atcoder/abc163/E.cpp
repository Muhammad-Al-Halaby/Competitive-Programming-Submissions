#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e3 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;

pii a[N];

ll dp[N][N];

ll solve(int i, int l){
    if(i == n)  return 0;

    ll &ret = dp[i][l];
    if(~ret)    return ret;

    ret = (ll)a[i].F * abs(a[i].S - l) + solve(i + 1, l + 1);
    ret = max(ret, (ll)a[i].F * abs(a[i].S - (n - 1 - (i - l))) + solve(i + 1, l));

    return ret;
}

int main(){
    init();

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a, a + n); reverse(a, a + n);

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0);
}