#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m, ans=0;
    cin >> n >> m;
    pair<int, int> arr[m];
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        arr[i] = make_pair(y,x);
    }
    sort(arr,arr+m);
    for(int i = m-1;i>=0;i--){
        if(arr[i].second <= n){
            ans += arr[i].second * arr[i].first;
            n -= arr[i].second;
        }
        else{
            ans += n * arr[i].first;
            break;
        }
    }
    cout << ans;
}
