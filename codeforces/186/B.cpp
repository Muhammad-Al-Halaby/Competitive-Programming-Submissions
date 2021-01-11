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

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main(){
    init();
    int n,t1,t2,k;
    cin >> n >> t1 >> t2 >> k;
    pair<double, int> ans[n];
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        double h = a * t1 - (a * t1)*(k/100.0) + b * t2;
        h = max(h,b * t1 - (b * t1)*(k/100.0) + a * t2);
        ans[i].first = h;
        ans[i].second = i+1;
    }
    sort(ans,ans+n,cmp);
    for(int i = 0;i<n;i++)
        cout << fixed << setprecision(2) << ans[i].second << " " << ans[i].first << '\n';
}