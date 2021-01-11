#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, a[N], av;

ll dp[55][55][M];

ll solve(int i, int cnt, int sum){
    if(i == n)
        return (cnt != 0 && sum % cnt == 0 && sum / cnt == av);

    ll &ret = dp[i][cnt][sum];
    if(~ret)    return ret;

    return ret = solve(i + 1, cnt + 1, sum + a[i]) + solve(i + 1, cnt, sum);
}
int main(){
    init();

    cin >> n >> av;
    for(int i = 0;i < n;i++)    cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);
}