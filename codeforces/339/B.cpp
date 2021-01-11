#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,m,curr=1;
    ll ans = 0;
    cin >> n >> m;
    for(int i =0;i < m;i++){
        int a;
        cin >> a;
        if(curr > a)
            ans += n-curr+a;
        else
            ans += a - curr;
        curr = a;
    }
    cout << ans;
}