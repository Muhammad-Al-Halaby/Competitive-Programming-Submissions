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

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    ll n, a, b;  cin >> n;

    a = b = 0;
    for(int i = 0;i < n;i++){
        ll x, y;    cin >> x >> y;
        ll gcd = __gcd(x, y);   x /= gcd, y /= gcd;
        ll l = 1, r = 1e18 / max(x, y);
        while(l <= r){
            ll mid = (l + r) >> 1;
            ll na = x * mid;
            ll nb = y * mid;
            if(na - a >= 0 && nb - b >= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }

        a = x * l;
        b = y * l;
    }

    cout << a + b;
}