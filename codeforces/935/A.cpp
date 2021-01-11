#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,ans=0;
    cin >> x;
    for(int i = 1;i<x;i++){
        if((x-i) % i == 0)ans++;
    }
    cout << ans;
}