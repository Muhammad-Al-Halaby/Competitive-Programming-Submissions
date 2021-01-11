#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();
    
    int n;  cin >> n;

    n++;
    ll a[n + 1];
    a[0] = 0;

    ll sum = 0;
    for(int i = 1;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n);

    ll prefix = 0;

    ll num = 0;
    for(int i = 1;i < n;i++){
        ll suffix = sum - prefix - a[i];
//        num += (i * a[i] - prefix) * rep + (suffix - (n - i - 1) * a[i]) * rep;
        num += (i * a[i] - prefix) + (suffix - (n - i - 1) * a[i]);
        prefix += a[i];
    }

    ll fac = n - 1;
    ll g = gcd(num, fac);
    fac /= g;
    num /= g;
   
    cout << num << " " << fac << endl;
}