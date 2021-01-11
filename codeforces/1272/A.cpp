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

const int N = 5e3 + 5, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int solve(int x){
    if(x == 1)  return 1;
    else if(x & 1)   return 1 + solve(x * 3 + 1);
    return 1 + solve(x / 2);
}
int main(){
    init();

    int q;  cin >> q;
    while(q--){
        ll a, b, c;    cin >> a >> b >> c;
        ll ans = LLONG_MAX;
        for(int i = -1;i < 2;i++){
            for(int j = -1;j < 2;j++){
                for(int k = -1;k < 2;k++){
                    ll x = a + i, y = b + j, z = c + k;
                    ans = min(ans, abs(x - y) + abs(x - z) + abs(y - z));
                }
            }
        }

        cout << ans << '\n';
    }

}





