#include<bits/stdc++.h>

using namespace std;
int main(){
    double n,p,q,x,y,factor;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    bool got_it = false;
    factor = 0;
    while(!got_it){
        x = factor;
        y = (n-(x*p))/q;
        if(int(x) == x && int(y) == y)got_it = true;
        else if(y < 0)got_it = true;
        factor++;
  
    }
    if(y >= 0){
        //cout << x << " " << y << endl;
        cout << x+y << endl;
        int start = 0;
        for(int i = 0;i<x;i++){
            for(int j = start;j < start+p;j++)cout << s[j];
            start += p;
            cout << endl;
        }
        for(int i = 0;i<y;i++){
            for(int j = start;j < start+q;j++)cout << s[j];
            start += q;
            cout << endl;
        }
    }else cout << -1;
}