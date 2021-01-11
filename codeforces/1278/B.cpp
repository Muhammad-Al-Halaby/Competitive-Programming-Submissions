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

const int N = 1e5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll a, b;


int main(){
    init();


    int t;  cin >> t;
    while(t--){
        cin >> a >> b;
        ll temp = min(a, b);
        b = max(a, b);
        a = temp;
        ll l = 0, r = 1e5;
        while(l <= r){
            ll mid = (l + r) >> 1;
            ll diff = (mid * (mid + 1) / 2 + a) - b;
            if(diff >= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }

        while(true){
            ll diff = (l * (l + 1) / 2 + a) - b;
            if(diff % 2 == 0)   break;
            else l++;
        }

        cout << l << '\n';
    }
}