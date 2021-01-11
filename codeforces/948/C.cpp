#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    /* Sometimes you win, sometimes you learn */
    int n;
    cin >> n;

    ll p[n+1],t[n+1],partial[n+2],complete[n+2];

    fill(t,t+n+1,0);
    fill(partial,partial+n+1,0);
    fill(complete,complete+n+2,0);

    for(int i = 1;i<=n;i++)
        cin >> p[i];

    for(int i = 1;i<=n;i++){
        cin >> t[i];
        t[i] += t[i-1];
    }

    for(int i = 1;i <= n;i++){
        ll past = t[i-1];
        int last_day = upper_bound(t+(i-1),t+n+1,p[i] + past) - t;

        partial[i]++;
        if((p[i] - t[last_day]) >= 0)
            partial[last_day+1]--;
        else{
            partial[last_day]--;
            complete[last_day] += min(t[last_day]-t[last_day-1], p[i] - (t[last_day-1] - t[i-1]));
        }
    }

    for(int i = 1; i<=n;i++)
        partial[i] += partial[i-1];

    for(int i = 1;i <= n;i++){
        ll ans = partial[i] * (t[i]-t[i-1]) + complete[i];
        cout << ans << " ";
    }
}