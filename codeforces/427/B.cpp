#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,t,c,cnt=0;
    ll ans=0;
    cin >> n >> t >> c;
    for(int i = 0;i<n;i++){
        int x;cin >> x;
        if(x <= t)cnt++;
        else cnt = 0;
        if(cnt == c){ans++;cnt--;}
    }
    cout << ans;
}