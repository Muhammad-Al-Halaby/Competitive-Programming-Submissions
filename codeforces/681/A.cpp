#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool ans=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        string s;
        int b,a;
        cin >> s >> b >> a;
        if(a>b && b>=2400)ans=1;
    }
    if(ans)cout << "YES";
    else cout << "NO";
}