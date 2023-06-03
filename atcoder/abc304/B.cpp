#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;


    if(n < 1000 - 1)
        cout << n;
    else if(n >= 1000 and n <= 10000-1){
        cout << n / 10 * 10;
    }
    else if(n >= 10000 and n <= 100000-1){
        cout << n / 100 * 100;
    }
    else if(n >= 100000 and n <= 1000000-1){
        cout << n / 1000 * 1000;
    }
    else if(n >= 1000000 and n <= 10000000-1){
        cout << n / 10000 * 10000;
    }
    else if(n >= 10000000 and n <= 100000000-1){
        cout << n / 100000 * 100000;
    }
    else if(n >= 100000000 and n <= 1000000000-1){
        cout << n / 1000000 * 1000000;
    }

}