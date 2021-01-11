#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int c1,c2,c3;cin>>c1>>c2>>c3;
        int a1,a2,a3,a4,a5;cin>>a1>>a2>>a3>>a4>>a5;
        int total1=a1+a4;
        int total2=a2+a5;
        total1-=min(total1,c1);
        total2-=min(total2,c2);
        if(total1+total2+a3<=c3&&a1<=c1&&a2<=c2&&a3<=c3)cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}