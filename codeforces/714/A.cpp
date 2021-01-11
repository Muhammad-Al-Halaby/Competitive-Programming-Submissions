#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    long long l1,r1,l2,r2,k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    long long x,y;
    x = max(l1,l2);
    y = min(r1,r2);
    if(y < x)cout << 0;
    else if(k >= x && k <= y)cout << (y-x);
    else cout << y-x+1;
}
