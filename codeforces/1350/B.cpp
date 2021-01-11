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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, a[N];

int dp[N];

int solve(int i){
    if(2 * i > n)   return 0;

    int &ret = dp[i];
    if(~ret)    return ret;

    ret = 0;
    for(int j = 2 * i;j <= n;j+=i){
        if(a[j] > a[i])
            ret = max(ret, 1 + solve(j));
    }

    return ret;
}

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;

        for(int i = 1;i <= n;i++)    cin >> a[i];

        int ans = 0;

        memset(dp, -1, sizeof dp);

        for(int i = 1;i <= n;i++)   ans = max(ans, solve(i));

        cout << ans + 1 << '\n';
    }
}
