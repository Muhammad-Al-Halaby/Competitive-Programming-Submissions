#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    ll l,r;
    cin >> l >> r;
    cout << "YES" << '\n';
    while(l < r){
        cout << l << " " << l+1 << '\n';
        l+=2;
    }
}