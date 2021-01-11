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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    ll n, t;    cin >> n >> t;

    ll last = 0, ans = t;
    for(int i = 0;i < n;i++){
        ll x;  cin >> x;
        ans += (x - last > t ? t : x - last);
        last = x;
    }

    cout << ans;
}