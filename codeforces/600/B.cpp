#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i = 0;i<m;i++){
        int q;
        cin >> q;
        cout << upper_bound(a,a+n,q) - a << " ";
    }
}