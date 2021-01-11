#include <bits/stdc++.h>
using namespace std;

int main(){
    long long l,r;
    cin >> l >> r;
    if(l % 2 != 0 && (r-l) == 2 ||r-l<2)cout << -1;
    else if(l % 2 == 0)cout << l << " " << l+1 << " " << l+2;
    else cout << l+1 << " " << l+2 << " " << l+3;
}