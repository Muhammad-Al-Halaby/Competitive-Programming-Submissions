#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    ll n,k,ts,nn,p=0;
    cin >> n >> k;
    nn = n;
    while(nn)nn>>=1,p++;
    if(k == 1)cout << n;
    else cout << (1ll << p) - 1;
}