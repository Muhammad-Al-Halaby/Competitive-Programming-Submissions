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

ll n, a, b, x[N];

int main(){
    init();


    cin >> n >> a >> b;
    for(int i = 0;i < n;i++)    cin >> x[i];

    ll ans = 0;
    for(int i = 1;i < n;i++){
        ans += min((x[i] - x[i - 1]) * a, b);
    }

    cout << ans;
}