#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n;
    cin >> n;
    int in[n],s[n];
    for(int i = 0;i<n;i++){
        cin >> in[i];
        s[i] = in[i];
    }
    sort(s,s+n);
    for(int i = 0;i<n;i++){
        cout << 1+n-(upper_bound(s,s+n,in[i])-s) << " ";
    }
}