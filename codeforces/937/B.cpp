#include<bits/stdc++.h>
using namespace std;

int main(){
    int p, y, e;
    cin >> p >> y;
    for(int i = y;i>p;i--){
        int h = i/2;
        bool yes = 1;
        for(int j = 2;j<=p && j*j <= i;j++){
            if(i % j == 0){
                yes = 0;
                break;
            }
        }
        if(yes){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}