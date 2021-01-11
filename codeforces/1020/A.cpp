#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie();
    cin.sync_with_stdio();
}

int main(){
    init();
    /* Sometimes you win, sometimes you learn */
    int n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    for(int i = 0;i<k;i++){
        int t1,f1,t2,f2;
        cin >> t1 >> f1 >> t2 >> f2;
        if(t1 == t2)
            cout << abs(f1-f2) << '\n';
        else{
            int d = 0,ff = f1;
            if(f1 < a) {d = abs(f1-a); ff= a;}
            else if(f1 > b){d = abs(f1-b); ff = b;}
            d += abs(t1-t2);
            d += abs(ff-f2);
            cout << d << '\n';
        }

    }
}