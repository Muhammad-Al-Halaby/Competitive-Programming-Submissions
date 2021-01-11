#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int k,ans=13;
    cin >> k;
    int arr[12];
    for(int i = 0;i<12;i++)cin >> arr[i];

    for(int mask = 0;mask < (1 << 12);mask++){
        int grow = 0, m = 0;
        for(int bit = 0;bit < 12;bit++){
            if(mask & (1 << bit))grow += arr[bit],m++;
        }
        if(grow >= k)ans = min(ans,m);
    }
    
    if(ans == 13)cout << -1;
    else cout << ans;
}