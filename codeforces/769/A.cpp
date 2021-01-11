#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    cout << arr[n/2];
}