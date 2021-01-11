#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 	3.14159265358979323846

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = min(n,k), mid;

    while(l < r){
        mid = (l+r) / 2;
        if(k - mid <= n && k-mid > 0)
            r = mid;
        else
            l = mid+1;
    }

    ll ans = (min(n,k) - l + 1) / 2;

    if(k%2 == 0 && (min(n,k) - l + 1) == k)
        ans -= 1;
    cout << max(0ll,ans);
}