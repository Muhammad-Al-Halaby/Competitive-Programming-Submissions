#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    bool cool=1;
    for(int i = 0;i<n;i++)cin >> arr[i];
    
    for(int i = k-1;i<n;i++)
        if(i+1 < n)if(!(arr[i] == arr[i+1]))cool = false;
    
    if(cool)
        for(int i = k-2;;i--){
            if(arr[i] != arr[k-1]){
                cout << i+1;
                break;
            }
        }
    else cout << -1;
}