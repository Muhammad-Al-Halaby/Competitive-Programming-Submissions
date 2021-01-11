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

const int N = 2e5 + 9, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}


int main(){
    init();

    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    for(int i = sx;i < tx;i++)  cout << 'R';
    for(int i = sy;i < ty;i++)  cout << 'U';
    for(int i = sx;i < tx;i++)  cout << 'L';
    for(int i = sy;i < ty;i++)  cout << 'D';
    cout << 'L';
    for(int i = sy;i <= ty;i++)  cout << 'U';
    for(int i = sx;i <= tx;i++)  cout << 'R';
    cout << 'D';

    cout << 'R';
    for(int i = sy;i <= ty;i++)  cout << 'D';
    for(int i = sx;i <= tx;i++)  cout << 'L';
    cout << 'U';
}