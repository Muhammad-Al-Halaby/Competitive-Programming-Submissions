#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

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
    int n,mn=INT_MAX,last_idx=-1,ans=INT_MAX;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(arr[i] < mn) mn = arr[i], last_idx = i;
    }
    for(int i = last_idx+1;i<n;i++)
        if(arr[i] == mn)
            ans = min(ans,i-last_idx), last_idx = i;

    cout << ans;
}