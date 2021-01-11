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

const int N = 109, M = 509, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, cap, w[N], v[N], first;

ll dp[N][N][M];

ll solve(int i, int cnt, int total){
    if(i == n)  return ((ll)cnt * first + total  <= cap ? 0 : -llOO);

    ll &ret = dp[i][cnt][total];
    if(~ret)    return ret;

    return ret = max(v[i] + solve(i + 1, cnt + 1, total + w[i]), solve(i+ 1, cnt, total));
}
int main(){
    init();

    cin >> n >> cap;
    for(int i = 0;i < n;i++){
        cin >> w[i] >> v[i];
        if(!i)  first = w[i];
        w[i] -= first;
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);
}