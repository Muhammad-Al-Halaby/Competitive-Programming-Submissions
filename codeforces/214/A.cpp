#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,m,ans=0;
    cin >> n >> m;
    for(int i = 0;i < 32;i++){
        if((m * m - 2 * m * i * i + i*i*i*i + i) == n && (m - i * i) >= 0)
            ans++;
    }
    cout << ans;
}