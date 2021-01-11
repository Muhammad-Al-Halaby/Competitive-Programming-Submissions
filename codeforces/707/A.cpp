#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,bw=true;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;
            cin >> c;
            if(c!='W' && c!='B' && c!='G')bw=false;
        }
    }
    if(bw)cout << "#Black&White";
    else cout << "#Color";
}