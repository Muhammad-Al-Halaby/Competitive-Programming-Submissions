#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,pairs=0;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){cin>>arr[i];if(arr[i]==1)pairs++;}
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            if(i != 0 && i+1<n && arr[i+1] != 0 && arr[i-1] != 0)pairs++;
        }
    }
    cout << pairs;
}