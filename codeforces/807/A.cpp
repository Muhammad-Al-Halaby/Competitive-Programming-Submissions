#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,mn=1e9,un=0,ans=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(abs(a-b) > 0)ans = 1;
        if(i == 0){
            mn = min(mn,b);
        }else{
            if(b > mn)un = 1;
            mn = min(mn,b);
        }
    }
    if(ans){
            cout << "rated";
            return 0;
    }
    else if(un){
            cout << "unrated";
            return 0;
    }
    cout << "maybe";
}