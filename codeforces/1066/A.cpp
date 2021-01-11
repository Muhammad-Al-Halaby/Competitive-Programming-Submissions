#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int L,v,l,r;
        cin >> L >> v >> l >> r;
        ll ans = 0;
        ans += (l-1) / v;
        ans += L/v - (r/v);
        cout << ans << '\n';
    }
}

