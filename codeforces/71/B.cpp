#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n, k, t;
    cin >> n >> k >> t;
    int x = t * n * k / 100;
    while(true){
        if(x / k + bool(x % k) <= n)break;
        x--;
    }

    for(int i = 0;i<x/k;i++)
        cout << k << " ";

    if(x % k > 0)
        cout << x % k << " ";
    int rest = n - x/k - bool(x % k);

    for(int i = 0;i<rest;i++)
        cout << 0 << " ";
}