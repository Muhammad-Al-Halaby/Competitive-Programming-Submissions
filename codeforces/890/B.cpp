#include <bits/stdc++.h>
using namespace std;

int arr[2000005];

int main(){
    int n, mini=2000005,ans=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;cin >> x;
        arr[x]=i+1;

    }
    for(int i = 0;i<2000005;i++){
        if(arr[i] != 0 && arr[i] < mini){
            mini=arr[i];
            ans=i;
        }
    }

    cout << ans;
}
