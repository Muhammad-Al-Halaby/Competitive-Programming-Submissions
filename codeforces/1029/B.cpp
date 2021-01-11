#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,s=0,ans=1;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];

    for(int i = 1;i<n;i++){
        if(arr[i] <= 2 * arr[i-1])
            ans = max(ans,i-s+1);
        else
            s = i;
    }
    cout << ans;
}