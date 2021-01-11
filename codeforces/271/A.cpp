#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool distinct = false;
    while(!distinct ){
        distinct = true;
        n++;
        int a=n%10,t=n%100/10,h=n%1000/100,th = n/1000;
        if(th==h||th==t||th==a||h==t||h==a||t==a)distinct = false;
    }
    cout << n;
}