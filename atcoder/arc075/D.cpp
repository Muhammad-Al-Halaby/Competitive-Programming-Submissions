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

const int N = 3005, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



void go(int tc = 0){
    ll n, a, b;    cin >> n >> a >> b;

    ll h[n];

    for(int i = 0;i < n;i++)    cin >> h[i];

    auto check = [&](int t){
        ll op = 0;
        for(int i = 0;i < n;i++){
            ll rest = max(0ll, (h[i] - b * t));
            op += ceil(1.0 * rest / (a - b));
        }
        return op <= t;
    };


    ll l = 1, r = 1e9;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}