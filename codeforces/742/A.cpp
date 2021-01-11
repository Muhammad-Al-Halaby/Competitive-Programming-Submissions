#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n==0)cout << 1;
    else if(n%2==0){
        if((n/2) % 2 == 0)cout << 6;
        else cout << 4;
    }
    else{
        if(((n-1) / 2) % 2 == 0)cout << 8;
        else cout << 2;
    }
}