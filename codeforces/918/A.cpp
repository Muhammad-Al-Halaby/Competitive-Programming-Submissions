#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,i=1,x=0,y=1,f=0;
    cin >> n;
    while(i <= n){
        while(f < i){
            f=x+y;
            x=y;
            y=f;
        }
        if(i == f)cout << 'O';
        else cout << 'o';
        i++;
    }
}