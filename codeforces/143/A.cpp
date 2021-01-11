#include <bits/stdc++.h>
using namespace std;
int main(){
    int r1,r2,c1,c2,d1,d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a,b,c,d;
    a=(r1+d1-c2)/2;b=r1-a;c=c1-a;d=r2-c;
    if(a > 0 && a <= 9 && b > 0 && b <= 9 && c > 0 && c <= 9 && d > 0 && d <= 9
    && a != b && a != c && a != d && b != c && b != d && c != d
    && r1 == a+b && r2 == c+d && c1 == a+c && c2 == b+d && d1 == a+d && d2 == b+c)
        cout << a << " " << b << endl << c << " " << d;
    else cout << -1;
}