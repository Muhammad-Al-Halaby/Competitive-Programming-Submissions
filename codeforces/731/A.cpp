#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans=0,current=0;
    string x;
    cin >> x;
    for(int i = 0;i<x.length();i++){
        int j = abs(x[i]-'a' - current);
        ans+=min(j,abs(26-j));
        current=x[i]-'a';
    }
    cout << ans;
}
