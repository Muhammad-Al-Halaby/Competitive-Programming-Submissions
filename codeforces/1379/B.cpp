#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


bool in_range(ll x, ll l, ll r){
    return x >= l && x <= r;
}

void go(int tc = 0){
    ll l, r, m; cin >> l >> r >> m;


    ll lower = l - r, upper = -lower;
    ll mx = m + upper;
    ll mn = max(m + lower - 1, 0ll);

    for(int a = l;a <= r;a++){
        ll cnt = mx/a - mn/a;
        if(cnt){
            ll low = (m / a) * a;
            ll high = ceil(1.0 * m / a) * a;
            if(low > 0 && m - low <= upper){
                ll diff = m - low;
                ll b = r;
                ll c = r - diff;
                cout << a << " " << b << " " << c << '\n';
                break;
            }
            else if(high - m <= upper){
                ll diff = high - m;
                ll b = r - diff;
                ll c = r;
                cout << a << " " << b << " " << c << '\n';
                break;
            }
        }
    }
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
    cin >> t;
    while(t--)
        go(tc++);
}