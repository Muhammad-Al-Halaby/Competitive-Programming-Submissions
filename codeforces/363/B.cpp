#include <bits/stdc++.h>
using namespace std;

long long arr[int(1e5*1.5)];
int main(){
    int n,k,j;
    cin >> n >> k;
    long long ans=0xFFFFFFFFFFF;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for(int i = 1;i<=n-k+1;i++){
        if(arr[i+k-1]-arr[i-1] < ans){
            ans = arr[i+k-1]-arr[i-1];
            j = i;
        }
    }
    cout << j;
}