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

const int N = 1e5 + 9, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    ll x;   cin >> x;
    if(x < 7)   return cout << 1, 0;
    if(x < 12)  return cout << 2, 0;

    ll op = x / 11, a = 0, b = 0, p = 0;
    while((op + a) * 5 + (op + b) * 6 < x){
        if(p)   a++;
        else b++;
    }
    cout << op * 2 + a + b;
}