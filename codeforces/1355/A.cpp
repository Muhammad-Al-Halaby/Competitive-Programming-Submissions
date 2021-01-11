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


int getmxmn(ll x, bool b){
    int mn = 9, mx = 0;
    while(x){
        int ld = x % 10;
        mx = max(ld, mx);
        mn = min(ld, mn);
        x /= 10;
    }

    if(b)   return mx;
    return mn;
}
int main(){
    init();

    int t;  cin >> t;
    while(t--){
        ll a, k;    cin >> a >> k;
        for(int i = 1;i < k;i++){
            ll b = a;
            a = a + getmxmn(a, 1) * getmxmn(a, 0);
            if(a == b)  break;
        }

        cout << a << '\n';
    }

}