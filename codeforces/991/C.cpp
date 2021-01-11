#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2005, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    ll n;   cin >> n;
    ll half = n / 2 + n % 2;
    auto check = [&](ll k){
        ll a = 0, b = 0;
        ll nn = n;
        while(nn > 0){
            a += min(nn, k);
            nn -= min(nn, k);

            b += nn / 10;
            nn -= nn / 10;
        }
        if(a >= half)   return true;
        return false;
    };

    ll l = 1, r = n;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}







