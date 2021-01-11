#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll factorial[N];

int main(){
    init();

    factorial[0] = 1;
    for(int i = 1;i < N;i++)
        factorial[i] = (factorial[i - 1] * i) % modulo;

    int n, m;   cin >> n >> m;

    if(abs(n - m) > 1)   return cout << 0, 0;

    cout << (factorial[n] * factorial[m] * (n - m == 0 ? 2 : 1)) % modulo;
}