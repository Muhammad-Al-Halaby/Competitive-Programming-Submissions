#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    ll n,last1 = -1,ans=1;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x && last1 == -1)last1 = i;
        else if(x)ans *= i - last1, last1 = i;
    }
    if(last1 == -1)ans = 0;
    cout << ans;
}