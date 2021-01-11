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

const int N = 109, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, d;

ll dp[N][2];

ll solve(int rem, bool b){
    if(rem == 0)    return b;

    if(rem < 0) return 0;

    ll &ret = dp[rem][b];
    if(~ret)    return ret;

    ret = 0;
    for(int j = 1;j <= k;j++){
        ret += solve(rem - j, b | (j >= d));
        while(ret >= modulo)    ret -= modulo;
    }

    return ret;
}

int main(){
    init();

    cin >> n >> k >> d;

    memset(dp, -1, sizeof dp);

    cout << solve(n, 0);

}