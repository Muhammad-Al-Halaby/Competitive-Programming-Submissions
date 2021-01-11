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

const int N = 109, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    ll n, r, avg;  cin >> n >> r >> avg;
    pii a[n];
    ll sum = 0;
    for(int i = 0;i < n;i++)    cin >> a[i].S >> a[i].F, sum += a[i].S;

    sort(a, a + n);

    ll rem = max(0ll, avg * n - sum);

    ll ans = 0, i = 0;
    while(rem){
        int take = min(rem, r - a[i].S);
        rem -= take;
        ans += (ll)a[i].F * take;
        i++;
    }

    cout << ans;
}
