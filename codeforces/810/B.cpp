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
    int n,f;
    cin >> n >> f;
    vector<ll> could;
    ll sum = 0;
    for(int i = 0;i<n;i++){
        ll k,l;
        cin >> k >> l;

        if(k >= l)
            sum += l;
        else{
            sum += k;
            could.push_back(2 * k > l? l-k : k);
        }
    }
    sort(could.begin(),could.end());
    for(int i = could.size() - 1;i>=0 && f;i--,f--){
            sum += could[i];
    }
    cout << sum;
}
