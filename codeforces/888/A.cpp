#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
for(int i = 0;i<n;i++){
        
        if(i > 0 && i < n-1){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])ans++;
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])ans++;
        }
    }
    cout<<ans;
}