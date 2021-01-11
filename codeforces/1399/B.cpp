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

const int N = 1e6 + 10, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n;  cin >> n;
    int a[n], mna = OO;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        mna = min(mna, a[i]);
    }

    int b[n], mnb = OO;
    for(int i = 0;i < n;i++){
        cin >> b[i];
        mnb = min(mnb, b[i]);
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll d1 = abs(mna - a[i]);
        ll d2 = abs(mnb - b[i]);
        ll x = min(d1, d2);
        ans += x;
        ans += d1 + d2 - 2 * x;
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