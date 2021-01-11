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

const int N = 5e3 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], dp[N][N], temp;

//int solve(int i, int sum){
//    if(i == n)  return (sum >= k - temp && sum < k);
//
//    int &ret = dp[i][sum];
//    if(~ret)    return ret;
//
//    return ret = solve(i + 1, sum) | solve(i + 1, min(k, sum + a[i]));
//}

int solve(){
    for(int i = 0;i < N;i++)
        for(int sum = 0;sum < N;sum++)
            dp[i][sum] = (sum >= k - temp && sum < k);

    for(int i = N - 2;i >= 0;i--){
        for(int sum = N - 2;sum >= 0;sum--){
            dp[i][sum] = dp[i + 1][sum] | dp[i + 1][min(k, sum + a[i])];
        }
    }

    return dp[0][0];
}

int main(){
    init();

    cin >> n >> k;
    for(int i = 0;i < n;i++)    cin >> a[i];

    sort(a, a + n);
    while(n - 1 >= 0 && a[n - 1] >= k)  n--;

    int l = 0, r = n - 1;
    while(l <= r){
        int i = (l + r) >> 1;

        temp = a[i];    a[i] = 0;
//        memset(dp, -1, sizeof dp);
        int ok = !(solve());
        a[i] = temp;

        if(ok == 1)
            l = i + 1;
        else
            r = i - 1;
    }

    cout << l;
}