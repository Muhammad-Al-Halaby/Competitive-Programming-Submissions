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

const int N = 1e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int t;  cin >> t;
    while(t--){
        ll x, y, a, b; cin >> x >> y >> a >> b;
        if(x > y)   swap(x, y);


        ll c1 = (y - x) * a + y * b;

        ll c2 = (y - x) * a + x * b;

        ll c3 = x * a + y * a;

        cout << min({c1, c2, c3}) << '\n';
    }


}




