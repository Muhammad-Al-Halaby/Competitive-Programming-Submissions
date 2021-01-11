#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, g,b, ans = 0;
    cin >> r >> g >> b;
    if(r && b && g)
        cout << max((r/3 + g/3 + b/3) ,max((1+(r-1)/3 + (g-1)/3 + (b-1)/3), 2+((r-2)/3 + (g-2)/3 + (b-2)/3)));
    else
        cout << (r/3 + g/3 + b/3);
}