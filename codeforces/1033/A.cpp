#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EPS 1e-9

void init(){

    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ax,ay,bx,by,cx,cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    int mx = max(bx,cx);
    bx = min(bx,cx);
    cx = mx;
    mx = max(by,cy);
    by = min(by,cy);
    cy = mx;

    if(ax > bx && ax < cx || ay > by && ay < cy)
        cout << "NO";
    else
        cout << "YES";
}
