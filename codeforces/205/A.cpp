#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    int index=0, counter=0, min = *min_element(arr,arr+n);
    for(int i = 0;i<n;i++)if(arr[i] == min){counter++;index=i+1;}
    if(counter > 1)cout << "Still Rozdil";
    else cout << index;
}