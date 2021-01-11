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
    int n;
    cin >> n;
    int arr[n];
    vector<int> v;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i<n-1;i++)
        if(!arr[i] && arr[i-1] && arr[i+1])v.push_back(i);
    int ans = 0;
    for(int i = 0;i<v.size();i++){
        ans++;
        if(v[i]+2 == v[i+1]){
            i++;
        }
    }
    cout << ans;
    
}