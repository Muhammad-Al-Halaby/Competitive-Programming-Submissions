#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ans=INT_MAX,m,mx=0,secmx=0;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];

        if(!i)continue;

        if(a[i] - a[i-1] > mx)
            mx = a[i] - a[i-1],m=i-1;
        else
            secmx = max(secmx,a[i] - a[i-1]);
    }

    for(int i = 0;i<n-2;i++){
        int rm = a[i+2] - a[i];

        if(i+1 == m || i+1 == m+1)
            ans = min(ans,max(rm,secmx));
        else
            ans = min(ans,max(rm,mx));
    }

    cout << ans;
}