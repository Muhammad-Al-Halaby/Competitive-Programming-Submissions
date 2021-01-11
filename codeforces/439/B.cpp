#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
long long ans = 0;
    cin >> n >> x;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
for(int i = 0;i<n;i++){
if(i && x-1)x--;
ans += (long long) arr[i] * x;
}
    cout << ans;
}