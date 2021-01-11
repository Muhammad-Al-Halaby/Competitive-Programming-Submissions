#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll sum(ll x){
    x %= modulo;
    return (x * (x + 1) / 2) % modulo;
}

int main(){
    init();

    ll a, b;    cin >> a >> b;

    cout << (sum(b - 1) * ((b * sum(a) + a) % modulo)) % modulo;
}