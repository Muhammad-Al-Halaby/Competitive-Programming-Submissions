#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,counter=0;
    cin >> n >> k;
    int arr[2*n+1];
    
    for(int i = 0;i<=2*n;i++)
        cin >> arr[i];
    
    for(int i = 0;i<=2*n;i++){
        if(i%2!=0 && arr[i]-1 > arr[i-1] && arr[i]-1 > arr[i+1] && k){
            cout << --arr[i] << " ";
            k--;
        }else cout << arr[i] << " ";
    }
}