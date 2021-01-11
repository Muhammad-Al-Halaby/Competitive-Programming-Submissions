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

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    ll n, x;    cin >> n >> x;
    ll a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    ll ans = 0;
    for(int i = 0;i < n - 1;i++){
        ll sum = a[i] + a[i + 1];
        if(sum <= x)    continue;
        ll mn = min(a[i + 1], sum - x);
        a[i + 1] -= mn;
        ans += sum - x;
    }

    cout << ans;
}