#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if((a+b)%n)if((a+b)%n<0)cout << (a+b)%n+n;else cout << (a+b)%n;
    else cout << n;
}