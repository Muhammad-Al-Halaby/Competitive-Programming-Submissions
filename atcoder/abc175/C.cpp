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

const int N = 250, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void go(int tc = 0){
    ll x, k, d; cin >> x >> k >> d;

    ll moves = abs(ceil(1.0 * x / d));

    moves = min(moves, k);

    ll n = (x + (x > 0 ? -1 : 1) * moves * d);

    ll remMoves = k - moves;

    if(remMoves & 1){
        cout << min(abs(n + d), abs(n - d));
    }
    else{
        if(remMoves > 1)
            cout << min({abs(n), abs(n - 2 * d), abs(n + 2 * d)});
        else
            cout << abs(n);
    }

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