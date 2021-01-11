#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    ll a, b, x, y, n;   cin >> a >> b >> x >> y >> n;

    ll ans = llOO;
    ll tempa = a, tempb = b, tempn = n;
    {
        ll op = min(a - x, n);
        a -= op;
        n -= op;

        b -= min(b - y, n);

        ans = a * b;
    }
    {
        a = tempa, b = tempb, n = tempn;
        ll op = min(b - y, n);
        b -= op;
        n -= op;

        a -= min(a - x, n);

        ans = min(ans, a * b);
    }

    cout << ans << '\n';
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}