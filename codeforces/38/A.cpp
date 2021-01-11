#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,a,b,ans=0;
    cin >> n;
    int ranks_years[n-1];
    for(int i = 0;i<n-1;i++)cin >> ranks_years[i];
    cin >> a >> b;
    for(int i = a-1;i<b-1;i++){
        ans+=ranks_years[i];
    }
    cout << ans;
}