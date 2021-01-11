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

const int N = 2005, M = 26, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int w, a, b;    cin >> w >> a >> b;
    if(max(a, b) <= min(a + w, b + w))  return cout << 0, 0;
    if(b - (a + w) >= 0)  cout << b - (a + w);
    else cout << a - (b + w);
}
