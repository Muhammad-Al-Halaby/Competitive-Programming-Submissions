#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    double x,y,z,n,ans=0,l=0,w=0,h=0;
    cin >> x >> y >> z;
    l=sqrt((x/y)*z);
    h=sqrt((y/x)*z);
    w=x/l;
    ans=(l+w+h);
    cout << ans*4;
}