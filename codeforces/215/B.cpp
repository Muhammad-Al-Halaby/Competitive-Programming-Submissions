#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

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
    double n,m,k,a,b,mx_r1=-1,mx_p1=-1,mn_p2=INT_MAX;
    cin >> n;
    for(int i = 0;i<n;i++){
        double x;
        cin >> x;
        mx_r1 = max(mx_r1,x);
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        double x;
        cin >> x;
        mx_p1 = max(mx_p1,x);
    }
    cin >> k;
        for(int i = 0;i<k;i++){
        double x;
        cin >> x;
        mn_p2 = min(mn_p2,x);
    }
    cin >> a >> b;

    cout << setprecision(10) << mx_r1 * sqrt(b * mx_p1 / (a * mn_p2 + b * mx_p1));

}