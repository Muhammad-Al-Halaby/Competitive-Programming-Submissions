#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1
#define EPS 1e-7
#define go continue;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //cout.sync_with_stdio(0);
    //cout.tie(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    ll n,m;
    cin >> n >> m;
    ll arr[n];
    for(int i = 0;i < n;i++)cin >> arr[i];
    sort(arr,arr+n);
    int diag = 1;
    ll ans = 0, sum = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
        if(diag <= arr[i]){
            diag++;
        }
        ans++;
    }
    if(diag <= arr[n-1])
        ans += abs(arr[n-1] - diag + 1);
    cout << sum - ans;
}
