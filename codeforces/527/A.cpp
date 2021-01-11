#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    long long a,b,m=0;
    cin >> a >> b;
    while(a > 0 && b > 0){
        long long nmin = min(a,b),nmax = max(a,b);
        m += nmax/nmin;
        (a >= b) ? a=nmax%nmin : b=nmax%nmin;
    }
    cout << m;
}