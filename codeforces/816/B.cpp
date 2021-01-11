#include<bits/stdc++.h>

using namespace std;

int arr[(int)1e6];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,q;
    cin >> n >> k >> q;
    for(int i = 0;i<n;i++){
        int l,r;
        cin >> l >> r;
        arr[l]++;
        arr[r+1]--;
    }
    for(int i = 1;i<=200000;i++){
        arr[i] += arr[i-1];
    }
    for(int i = 1;i<=200000;i++){
        if(arr[i] >= k)
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    for(int i = 1;i<=200000;i++){
        arr[i] += arr[i-1];
    }
    for(int i = 0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << arr[r]-arr[l-1] << '\n';
    }
}