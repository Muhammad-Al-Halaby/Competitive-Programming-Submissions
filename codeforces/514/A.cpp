#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[10]={0,1,2,3,4,4,3,2,1,0},d=0;
    char c;
    while(cin >> c){
        if(d==0 && (c-'0')==9)cout << 9;
        else cout << arr[c-'0'];
        d++;
    }
}