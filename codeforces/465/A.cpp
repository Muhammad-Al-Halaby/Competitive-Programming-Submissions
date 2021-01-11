#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,ans=1;
    bool end=0;
    cin >> n;
    for(;n>0;n--){
        char x;
        cin >> x;
        if(x == '0')end=1;
        if(end == 0)ans+=1;
        
    }
    if(end)cout << ans;
    else cout << ans-1;
}