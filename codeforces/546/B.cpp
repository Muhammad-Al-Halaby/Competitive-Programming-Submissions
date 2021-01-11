#include <iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,cost = 0;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] == arr[j]){arr[j]++,cost++;};
        }
    }
    cout << cost;
}