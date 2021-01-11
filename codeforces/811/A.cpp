#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    for(int i = 1;;i++){
        if(i%2!=0)a-=i;
        else b-=i;
        if(a < 0){
            cout << "Vladik";
            break;
        }
        if(b < 0){
            cout << "Valera";
            break;
        }
    }
}