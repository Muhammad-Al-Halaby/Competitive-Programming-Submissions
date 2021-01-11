#include<bits/stdc++.h>
using namespace std;
int arr[3001];
int main(){
    int n; 
    cin >> n; 
    for(int i = 0;i<n;i++){
        int x; 
        cin >> x;
        arr[x]=1;
    }
    for(int i = 1;i<=3000;i++){
        if(!arr[i]){
            cout << i;
            return 0; 
        }
    }
    cout << 3001;
}