#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,b;
    cin >> n >> b;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int ev = 0,od=0,ans=0;
    vector<int> v;
    for(int i = 0;b > 0 && i<n-1;i++){
        if(arr[i] % 2)od++;
        else ev++;
        if(od == ev){
           v.push_back(abs(arr[i]-arr[i+1]));
            od = ev = 0;
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0 ;b > 0 && i<v.size();i++){
        ans++;
        b-=v[i];
    }
    if(b < 0)ans--;
    cout << ans;
}
