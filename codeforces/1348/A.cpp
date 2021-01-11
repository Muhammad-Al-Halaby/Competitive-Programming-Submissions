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
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
}

const int N = 1e5 + 9, M = 509, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        ll n;  cin >> n;
        ll x = (1ll << (n + 1)) - 2;
        x -= 2 * (1ll << n);
        for(int i = 1;i <= n / 2 - 1;i++){
            x -= 2 * (1ll << i);
        }

        cout << abs(x) << '\n';
    }
}
