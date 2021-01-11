#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e3 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int main(){
    init();

    ll n, m;    cin >> n >> m;
    if(n == m)  cout << max(n - 1, 1ll);
    else if(m == 1) cout << m + 1;
    else if(n - m > m - 1)  cout << m + 1;
    else cout << m - 1;
}
