#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,temp=1,maxi=1;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(i == 0)continue;
        if(arr[i]>=arr[i-1]){
            temp++;
            maxi = max(maxi,temp);
        }
        else
            temp = 1;
    }
    cout << maxi;
}