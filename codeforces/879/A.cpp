#include <bits/stdc++.h>

using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ans=0;
    cin >> n;
    int lastday;
    for(int i = 0;i<n;i++){
        int s,d;
        cin >> s >> d;
        if(i == 0){ans += s, lastday = s;continue;}
        if(s > lastday)ans += s-lastday,lastday = s;
        else ans += s + d * ((lastday-s)/d + 1) - lastday, lastday = s + d * ((lastday-s)/d + 1);
    }
    cout << ans;
}