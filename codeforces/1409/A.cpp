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
    int a, b;   cin >> a >> b;

    if(a > b)   swap(a, b);

    int d = b - a;

    int ans = 0;
    for(int i = 10;i >= 1;i--){
        ans += d / i;
        d %= i;
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