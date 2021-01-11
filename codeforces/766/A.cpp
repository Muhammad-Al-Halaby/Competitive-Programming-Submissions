#include<bits/stdc++.h>
 using namespace std;
int main(){
    string n,m;
    cin >> n >> m;
    if(n == m)cout << -1;
    else cout << max(n.length(),m.length());
}