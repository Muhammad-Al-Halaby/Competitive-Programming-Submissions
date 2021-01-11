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

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int a, b, c, d; cin >> a >> b >> c >> d;
    int p, q;
    
    if((1.0 * a / b) < (1.0 * c / d))
        p = b * c - a * d, q = b * c;
    else if((1.0 * a / b) > (1.0 * c / d))
        p = a * d - b * c, q = a * d;
    else
        p = 0, q = 1;

    int gcd = __gcd(p, q);

    cout << p / gcd << "/" << q / gcd;
}