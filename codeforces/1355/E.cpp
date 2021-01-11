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

int main(){
    init();

    ll n, a, rm, m; cin >> n >> a >> rm >> m;

    ll h[n], mn = 1e9, mx = 0;
    for(int i = 0;i < n;i++){
        cin >> h[i];
        mx = max(mx, h[i]);
        mn = min(mn, h[i]);
    }

    auto check = [&](int len){
        ll inc = 0, dec = 0;
        for(int i = 0;i < n;i++){
            inc +=  max(0ll, len - h[i]);
            dec +=  max(0ll, h[i] - len);
        }

        ll mn = min(inc, dec);
        inc -= mn, dec -= mn;

        ll cost = min(mn * m, mn * a + mn * rm);

        cost += inc * a + dec * rm;

        return cost;
    };

    int l = mn, r = mx;
    while(r - l > 2){
        int third = (r - l) / 3;
        int lf = l + third, rg = r - third;

        if(check(lf) < check(rg))
            r = rg;
        else
            l = lf;
    }

    cout << min({check(l), check(l+1), check(l+2)});
}