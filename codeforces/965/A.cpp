#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n,s,p;
    cin >> k >> n >> s >> p;
    int x = k*ceil(1.0*n/s);
    int y = ceil(1.0*x/p);
    cout << std::fixed << y;
}