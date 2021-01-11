#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();

    ll a,b,x,y,z,ans=0;
    cin >> a >> b >> x >> y >> z;

    a -= (2 * x + y);
    b -= (y + 3 * z);

    if(a < 0)ans += abs(a);
    if(b < 0)ans += abs(b);

    cout << ans;
}