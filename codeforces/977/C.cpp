#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    arr[n]= INT_MAX;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    if(k > 0 && arr[k-1] != arr[k])
        cout << arr[k-1];
    else if(k == 0 && arr[0]-1 > 0)
        cout << arr[0]-1;
    else cout << -1;
}