#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

bool islucky(int x){
    while(x){
        if(x%10 == 7)
            return 1;
        x /= 10;
    }
    return 0;
}

int main(){
    init();
    int x,h,m,hrs,mins,ans=0;
    cin >> x >> h >> m;
    hrs = h;
    mins = m;
    while(true){
        if(islucky(mins) || islucky(hrs))break;
        else ans++;
        if(mins - x < 0)mins+=60,hrs--;
        if(hrs < 0)hrs = 23;
        mins -= x;
    }
    cout << ans;
}