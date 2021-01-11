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

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    ll sum = accumulate(a, a + n, 0ll);

    if(sum % 3) return cout << 0, 0;

    sum /= 3;

    int suf[n + 1] = {0};
    for(ll s = 0, i = n - 1;i >= 0;i--){
        s += a[i];
        suf[i] = (s == sum) + suf[i + 1];
    }

    ll ans = 0;
    for(ll s = 0, i = 0;i < n - 2;i++){
        s += a[i];
        ans += (s == sum) * suf[i + 2];
    }

    cout << ans;
}