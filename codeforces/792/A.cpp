#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int n,m=2e9 + 5,counter=0;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
            if(i+1 < n && abs(arr[i]-arr[i+1]) < m){
                    m=abs(arr[i]-arr[i+1]);
                    counter=1;
            }
            else if(i+1 < n && m == abs(arr[i]-arr[i+1]))counter++;
    }
    cout << m << " " << counter;
}