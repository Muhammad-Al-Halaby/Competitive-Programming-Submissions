#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[4],ans=0;
    for(int i =0;i<4;i++){
        cin>>arr[i];
        for(int j = 0;j<i;j++)
            if(arr[i] == arr[j] && arr[j]!=0){ans++;arr[j]=0;}
    }
    cout << ans;
}