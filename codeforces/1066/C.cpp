#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int q;
    cin >> q;
    int l=0,r=0,s=1;
    map<int,int> idx;
    while(q--){
        char c;
        int id;
        cin >> c >> id;
        if(s && c == 'L')l++,s^=1;
        else if(s && c == 'R')r--,s^=1;
        if(c == 'L'){idx[id]=l-1;l = l-1;}
        else if(c == 'R'){idx[id]=r+1; r = r+1;}
        else cout << min(abs(idx[id]-l),abs(idx[id]-r)) << '\n';
    }
}