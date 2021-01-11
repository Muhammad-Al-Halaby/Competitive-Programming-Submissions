#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h=0, ans=0;
    cin >> n;
    int arr[n+1];
    arr[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++){
        if(arr[i] >= arr[i+1])
            h+=(arr[i] - arr[i+1]);
        else
            if(h >= abs(arr[i] - arr[i+1]))
                h-= abs(arr[i] - arr[i+1]);
            else{
                ans += abs(arr[i] - arr[i+1]) - h;
                h = 0;
            }
    }
    cout << ans;
}