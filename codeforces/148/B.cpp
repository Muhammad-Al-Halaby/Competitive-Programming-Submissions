#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();

    double p,d,t,f,c, ans = 0;
    cin >> p >> d >> t >> f >> c;

    double ppos = p * t,dpos = 0;

    if(p < d)
        while(ppos < c){
            double t = ppos / (d - p);
            if(t && ppos + p * t < c)ans++;
            ppos += p * t;
            ppos += p * (t + f);
        }

    cout << ans;
}