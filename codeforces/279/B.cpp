#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,t,ans=0,sum=0,s=0;
    cin >> n >> t;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
        while(sum>t)sum -= arr[s++];
        ans=max(ans,i-s+1);
    }
    cout << ans;
}