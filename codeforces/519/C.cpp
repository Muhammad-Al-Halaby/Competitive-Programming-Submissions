#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,m,teams=0;
    cin >> n >> m;
    int mn = min(n,m), mx = max(n,m);
    while(true){
        if(mn > 0 && mx - 2 >= 0){
            mn--;
            mx-=2;
            int temp = min(mn,mx);
            mx  = max(mn,mx);
            mn = temp;
            teams++;
        }
        if(mx - 2 < 0 || mn == 0)break;
    }
    cout << teams;
}