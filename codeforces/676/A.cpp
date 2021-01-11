#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    int n,onepos,maxpos;
    cin >> n;
    int arr[n+1];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(arr[i] == 1)onepos=i+1;
        else if(arr[i] == n)maxpos=i+1;
    }
    cout << max(max(n-onepos,onepos-1),max(n-maxpos,maxpos-1));
}