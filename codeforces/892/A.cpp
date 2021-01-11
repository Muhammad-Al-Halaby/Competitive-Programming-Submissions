#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,vol=0;
    cin >> n;
    long long arr[n];
    for(int i = 0;i<n;i++){
        long long x;
        cin >> x;
        vol+=x;
    }
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    if(arr[n-1] + arr[n-2] >= vol)cout << "YES";
    else cout << "NO";
}
