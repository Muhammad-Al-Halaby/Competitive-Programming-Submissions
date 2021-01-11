#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x=0,y=0,ans=0,gate=0,first=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        char c;
        cin >> c;
        if(c == 'R')x++;
        else y++;
        if(gate){
            if(first){
                if(y > x)ans++;
            }
            else{
                if(x > y)ans++;
            }
            gate=0;
        }
        if(x==y){
                gate=1;
        }
        else if(x > y)first=1;
        else first = 0;
    }
    cout << ans;
}