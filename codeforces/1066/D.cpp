#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    int arr[n];
    for(int i = n-1;i>=0;i--)
        cin >> arr[i];
    ll sz = 0, counter = 0;
    for(int i = 0;i <= n && m;i++){
        if(i < n && sz + arr[i] <= k)sz += arr[i],counter++;
        else{sz = (i < n)?arr[i]:0; ans += counter; counter = 1; m--;}
    }
    cout << ans;
}