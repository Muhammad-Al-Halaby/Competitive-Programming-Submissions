#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sindx,eindx,rs=0;
    bool f=0;
    char s,e;
    
    cin >> n;
    for(int i = 0;i<n;i++){
        char c;
        cin >> c;
        if(c != '.' && f == 0){
            s=c;
            sindx=i+1;
            f=1;
        }
        if(c!='.'){
            e=c;
            eindx=i+1;
            if(c == 'R')rs++;
        }
    }
    
    if(s == 'R'){
        if(e == 'R')
            cout << sindx << " " << eindx+1;
        else
            cout << sindx << " " << sindx+rs-1;
    }
    else
        cout << eindx << " " << sindx-1;
}