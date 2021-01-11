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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;   cin >> n >> m;

    ll x = 0;
    for(int i = 0;i < n;i++){
        ll a;  cin >> a;
        x += a * (n - i - 1) - a * i;
        x %= modulo;
    }

    ll y = 0;
    for(int i = 0;i < m;i++){
        ll a;  cin >> a;
        y += a * (m - i - 1) - a * i;
        y %= modulo;
    }

    cout << (x * y) % modulo;
}