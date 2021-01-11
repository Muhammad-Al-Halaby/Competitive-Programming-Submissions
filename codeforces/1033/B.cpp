#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EPS 1e-9

void init(){

    cin.tie(0);
    cin.sync_with_stdio(0);
}

bool isprime(ll x){
    for(ll i = 2;i * i <= x;i++){
        if(x % i == 0)return 0;
    }
    return 1;
}
int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if(a - b == 1){
            if(isprime(a+b))cout << "YES";
            else cout << "NO";
        }
        else cout << "NO";
        cout << '\n';
    }
}
