#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
    int n,sum=0,ans=true;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    
    for(int i = 0;i<=1000;i++)sum+=arr[i];
    
    for(int i = 0;i<=1000;i++){
        sum-=arr[i];
        if(sum < arr[i]-1){
            ans=false;
            break;
        }
        sum+=arr[i];
    }
    if(ans)cout<<"YES";
    else cout << "NO";
}