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

const int N = 5e3 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int f(ll a, ll b){
    int l1 = (a == 0), l2 = (b == 0);
    while(a)    l1++, a /= 10;
    while(b)    l2++, b /= 10;
    return max(l1, l2);
}

int main(){
    init();

    ll n;   cin >> n;

    int ans = OO;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ans = min(ans, f(i, n / i));
        }
    }

    cout << ans;
}