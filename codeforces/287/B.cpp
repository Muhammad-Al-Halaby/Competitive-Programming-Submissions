#include<bits/stdc++.h>

using namespace std;

long long n,k;

int sum(int a){
    long long s = (a+k) * (k-(a-1))/2 - (k-(a));
    if(s >= n)return true;
    return false;
}
int main(){
    cin >> n >> k;
    int l=2, r=k, ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(sum(mid)){
            l = mid + 1;
            ans = k-(mid-1);
        }
        else{
            r = mid-1;
        }
    }
    if(n == 1)cout << 0;
    else cout << ans;
}

