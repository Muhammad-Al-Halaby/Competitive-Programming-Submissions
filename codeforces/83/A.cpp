#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n;
    ll ans=0, cnt = 0;
    cin >> n;
    int arr[n+1];
    arr[0] = INT_MIN;
    ans += n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        if(arr[i] == arr[i-1])
            cnt++;
        else
            cnt = 0;
        ans += cnt;
    }
    cout << ans;
}