#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isLucky(int n){
    while(n){
        if(n%10 == 8)return 1;
        n/=10;
    }
    return 0;
}
int main(){
    int n, m, ans = 100;
    cin >> n;
    m = n;
    for(int i = n+1;i <= n+20;i++)
    if(isLucky(abs(i)) && i != n)ans = min(ans,abs(n-i));
    cout << ans;
}