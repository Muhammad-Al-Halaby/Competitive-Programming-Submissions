#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, dp[2][3], p = 0;
    memset(dp, 0x7f, sizeof dp);

    for(int i = 0;i<3;i++)
        dp[0][i] = 0;
    cin >> n;
 
    for(int i = 0;i<n;i++){
        int day;
        cin >> day;
        p^=1;

        for (int i = 0; i < 3; i++)
            dp[p][i] = 100;

        dp[p][0] = 1 + min(dp[!p][0], min(dp[!p][1], dp[!p][2]));
        if(day & 1)
        {
            dp[p][1] = min(dp[!p][0], dp[!p][2]);
        }
        if(day & 2){
            dp[p][2] = min(dp[!p][0], dp[!p][1]);
        }
        // cout << dp[p][0] << " " << dp[p][1] << " " << dp[p][2] << '\n';
    }
    cout << min(dp[p][0],min(dp[p][1],dp[p][2]));

    return 0;
}