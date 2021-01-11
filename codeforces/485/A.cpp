#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    long long a,m,t=0,ans=0;
    cin >> a >> m;
    bool divisble=false;
    while(!divisble){
        if((a+t) % m == 0){
            cout << "Yes";
            break;
        }
        else{
            t+=(a+(t%m)) % m;
        }
        if((a+t) > (m * m) ){
            cout << "No";
            break;
        }
    }
}