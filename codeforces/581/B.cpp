#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    vector<int> result;
    for(int i = 0;i<n;i++)cin >> arr[i];
    reverse(arr,arr+n);
    int maxi = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] > maxi){
            result.push_back(0);
            maxi = arr[i];
        }
        else result.push_back(maxi-arr[i]+1);
    }
    reverse(result.begin(),result.end());

    for(int i = 0;i<result.size();i++) cout << result[i] << " ";
}