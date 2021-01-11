#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int f=0,s=0,fr[100];
    fr['Q']=9;
    fr['R']=5;
    fr['B']=3;
    fr['N']=3;
    fr['P']=1;
    fr['K']=0;
    fr['.']=0;
    for(int i = 0;i<8;i++)
        for(int j = 0;j<8;j++){
            char c;
            cin >> c;
            if(isupper(c))f+=fr[c];
            else s+=fr[toupper(c)];
        }
    if(f == s)cout << "Draw";
    else if(f > s)cout << "White";
    else cout << "Black";
}