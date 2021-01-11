#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1
#define EPS 1e-7

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();
    
    int n;
    cin >> n;
    
    int x[n], v[n];
    for(int i = 0;i < n;i++)    cin >> x[i];
    for(int i = 0;i < n;i++)    cin >> v[i];
 
    auto check = [&](double t){
        double L = 0, R = 1e18;
        for(int i = 0;i < n;i++){
            L = max(L, x[i] - v[i] * t);
            R = min(R, x[i] + v[i] * t);
        }
        return L <= R;
    };
    
    double l = 0, r = 1e9;
    while(r - l > EPS){
        double mid = (l+r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    
    printf("%.8f", r);
}