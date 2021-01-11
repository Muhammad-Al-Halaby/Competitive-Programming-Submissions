#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,min=1000000,pos=0;
    cin >> n;
    int h[n];
    for(int i = 0;i<n;i++)cin >> h[i];
    for(int i = 0;i<n;i++){
        if(i+1 < n && abs(h[i+1]-h[i]) < min){
            min=abs(h[i+1]-h[i]);
            pos=i+1;
        }
    }
    if(abs(h[n-1]-h[0]) < min)cout << 1 << " " << n;
    else cout << pos << " " << pos+1;
}