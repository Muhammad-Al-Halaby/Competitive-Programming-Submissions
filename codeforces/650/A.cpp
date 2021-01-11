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
    int n;
    cin >> n;
    map<int, int> mpx, mpy;
    map<pair<int,int>, int> dup;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        mpx[x]++;
        mpy[y]++;
        dup[make_pair(x,y)]++;
    }

    ll ans = 0;
    for(auto p : mpx)
        ans += (ll)p.S * (p.S-1) / 2;

    for(auto p : mpy)
        ans += (ll)p.S * (p.S-1) / 2;

    for(auto p : dup)
        ans -= (p.S > 1)?(ll)p.S * (p.S-1) / 2:0;

    cout << ans;
}