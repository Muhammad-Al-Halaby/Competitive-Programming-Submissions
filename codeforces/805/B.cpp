#include<bits/stdc++.h>
using namespace std; 

int main() {
    int n,s=0,c=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        if(s==0){cout << 'a';c++;}
        else {cout << 'b';c++;}
        if(c==2){c=0;if(s==0)s=1;else s=0;}
    }
}