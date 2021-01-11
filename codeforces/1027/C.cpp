#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

long double eq(long double s1, long double s2){
    return  ((s1+s2)*2)*((s1+s2)*2) / (s1 * s2);
}

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        ll n,ans1,ans2;
        long double mn = LLONG_MAX;
        cin >> n;
        set<int> s;
        int fr[(int)1e4+1] = {0};
        int s1= 0,s2 = 0;
        for(int i = 0;i<n;i++){
            int a;
            cin >> a;
            fr[a]++;
            s.insert(a);
            if(fr[a] > 3)s1 = s2 = a;
        }
        if(!s1 && !s2){
            int r = 1;
            for(int a : s){
                if(r == 1){
                    if(fr[a] > 1)s1 = a;
                    else continue;
                }
                else{
                    if(fr[a] > 1)s2 = a;
                    else continue;
                }
                r ^= 1;
                if(!s2)continue;
                long double new_mn = eq(s1,s2);
                if(new_mn < mn){
                    mn = new_mn;
                    ans1 = s1;
                    ans2 = s2;
                }
            }
        }
        else{ans1 = s1;ans2 = s2;}
        cout << ans1 << " " << ans2 << " "  << ans1 << " " << ans2 << '\n';
    }
}