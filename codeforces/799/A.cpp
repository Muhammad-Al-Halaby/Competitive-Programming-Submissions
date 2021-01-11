#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t,k,d,one,left,both;
    cin >> n >> t >> k >> d;

    one = (n+k-1)/k * t;
    left = n-(d/t*k);
    both = d + ((((left+k-1)/k)+1) / 2) * t;

    if(both < one)cout << "YES";
    else cout << "NO";
}