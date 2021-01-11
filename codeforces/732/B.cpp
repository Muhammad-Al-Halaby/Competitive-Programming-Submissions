#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,k,sum=0;
    cin >> n >> k;
    int walks[n];
    for(int i = 0;i<n;i++){
        int x;cin >> x;
        if(i==0)walks[i]=x;
        else if((walks[i-1]+x) < k)walks[i]=k-walks[i-1];
        else walks[i]=x;
        sum += x;
        sum -= walks[i];
    }
    cout << abs(sum) << endl;
    for(int i = 0;i<n;i++)cout << walks[i] << " ";
}