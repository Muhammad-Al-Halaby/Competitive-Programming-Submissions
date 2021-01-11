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

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int x;  cin >> x;

    for(ll i = 0;i < 3000;i++){
        for(ll j = 0;j < 3000;j++){
            ll a = i * i * i * i * i;
            ll b = j * j * j * j * j;

            if(a - b == x)  return cout << i << " " << j, 0;
            if(a + b == x)  return cout << i << " " << -j, 0;
        }
    }

}