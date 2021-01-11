#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    while(true){
        n++;
        bool prime = true;
        for(int i = n/2;i>1;i--){
            if(n%i == 0)prime=false;
        }
        if(prime)
            if(n==m){
                cout << "YES";
                break;
            }
            else{
                cout << "NO";
                break;
            }
    }
}