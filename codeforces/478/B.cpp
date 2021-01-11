#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    
    ll n,m,mx,mn;
    cin >> n >> m;
    
    if(m > 1)
        m--,n--,n-=m,mx = n * (n+1) / 2,n+=m,n++,m++;
    if(m == 1)
        n--, mx = n * (n+1) / 2,n++;

    mn = ( ((n/m - 1) * (n/m)) / 2 ) * m;
    if(n % m)
        mn += (n/m) * (n % m); 
    
    cout << mn << " " << mx;
}