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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void solve(){

    int n, m;   cin >> n >> m;

    int ans = (m / 2) * n + (m & 1 ? ceil(n / 2.0) : 0);

    cout << ans << '\n';
}


int main(){
    init();

    int t;  cin >> t;
    while(t--)  solve();
}