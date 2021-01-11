#include <bits/stdc++.h>
using namespace std;

int diffBits(int x,int y){
    int diff = 0;
    while(x || y){
            diff += (x & 1) ^ (y & 1);
            x>>=1;
            y>>=1;

    }
    return diff;
}
int main(){
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    int arr[m+1];
    for(int i = 0;i<=m;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<m;i++){
        if(diffBits(arr[m],arr[i]) <= k)
            ans++;
    }
    cout << ans;
}