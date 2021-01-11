#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int n,ans=0;
    cin >> n;
    int m[366]={0},f[366]={0};
    for(int i = 1;i<=n;i++){
        char g;
        int s,e;
        cin >> g >> s >> e;
        if(g == 'M')for(int j = s-1;j<e;j++)m[j]+=1;
        else for(int j = s-1;j<e;j++)f[j]+=1;
    }
    int max=0;
    for(int i = 0;i<366;i++){
        if(2 * min(m[i],f[i]) > max){
            max=2 * min(m[i],f[i]);
        }
    }
    ans = max;
    cout << ans;
}