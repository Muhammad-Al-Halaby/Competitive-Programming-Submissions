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
    int xa, ya, xb, yb, n, ans = 0;
    cin >> xa >> ya >> xb >> yb >> n;

    int x[n], y[n], r[n];

    for(int i = 0;i<n;i++)
        cin >> x[i] >> y[i] >> r[i];

    if(xa > xb)swap(xa,xb);
    if(ya > yb)swap(ya,yb);

    int c = 0;

    for(int i = xa;i<=xb;i++){
        bool f = 0, s = 0;
        for(int j = 0;j<n;j++){

            if((i - x[j]) * (i - x[j]) + (ya - y[j]) * (ya - y[j]) <= r[j] * r[j])f=1;
            if((i - x[j]) * (i - x[j]) + (yb - y[j]) * (yb - y[j]) <= r[j] * r[j])s=1;
        }
        ans += !f + !s;
        if(!f && i == xa)c++;
        if(!s && i == xa)c++;
        if(!f && i == xb)c++;
        if(!s && i == xb)c++;
    }

    for(int i = ya;i<=yb;i++){
        bool f = 0, s = 0;
        for(int j = 0;j<n;j++){
            if((xa - x[j]) * (xa - x[j]) + (i - y[j]) * (i - y[j]) <= r[j] * r[j])f=1;
            if((xb - x[j]) * (xb - x[j]) + (i - y[j]) * (i - y[j]) <= r[j] * r[j])s=1;
        }
        ans += !f + !s;
        if(!f && i == ya)c++;
        if(!s && i == ya)c++;
        if(!f && i == yb)c++;
        if(!s && i == yb)c++;
    }

    c /= 2;
    ans -= c;
    cout << ans;
}