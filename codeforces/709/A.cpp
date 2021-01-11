#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,b,d,ans=0;
    long long waste=0;
    cin >> n >> b >> d;
    for(int i = 0;i<n;i++){
        long long x;
        cin >> x;
        if(x <= b)waste+=x;
        if(waste > d)waste=0,ans++;
    }
    cout << ans;
}