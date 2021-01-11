#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
    init();
    int n, ans = INT_MAX;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        int s = arr[i] * 2 + 1;
        int total = i + n - (lower_bound(arr,arr+n,s) - arr);
        ans = min(ans,total);
    }
    cout << ans;
}