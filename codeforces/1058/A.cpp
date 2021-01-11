#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ans=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x)ans=1;
    }
    if(ans)
        cout << "HARD";
    else
        cout << "EASY";
}
