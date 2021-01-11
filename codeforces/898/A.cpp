#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}
int main(){
    init();
    int n;
    cin >> n;
    int d = n%10;
    if(10-d < d)cout << n+(10-d);
    else cout << n-d;
}