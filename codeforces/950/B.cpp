#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n, m, ans = 0;
    cin >> n >> m;
    ll x[n + 1], y[m + 1];
    x[0] = 0;
    y[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll xi;
        cin >> xi;
        x[i] = x[i - 1] + xi;
    }
    for (ll i = 1; i <= m; i++)
    {
        ll yi;
        cin >> yi;
        y[i] = y[i - 1] + yi;
    }
    ll y_idx = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = y_idx; j <= m; j++)
        {
            if ((y[j]) > (x[i])){
                y_idx = j;
                break;
            }
            if (y[j] == x[i])
            {
                y_idx = j + 1;
                ans++;
                break;
            }
        }
    }

    cout << ans;
}