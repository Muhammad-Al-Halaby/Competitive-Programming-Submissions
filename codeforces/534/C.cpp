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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    ll n, d;    cin >> n >> d;

    ll sum = 0;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i], sum += a[i];

    for(int i = 0;i < n;i++){
        ll mxleft = sum - a[i];
        ll mnleft = d - (n - 1);

        ll ans = 0;

        ans += max(a[i] - mnleft, 0ll);
        ans += max(d - mxleft - 1, 0ll);

        cout << ans << " ";
    }
}