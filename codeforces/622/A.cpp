#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    long long n, i;
    cin >> n;
    for(i = 1;(i*(i+1))/2 < n;i++);
    i--;
    cout << n-(i*(i+1))/2;
}