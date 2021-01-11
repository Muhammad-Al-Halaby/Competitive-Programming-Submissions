#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r,a;
    cin >> l >> r >> a;
    if(l < r)
    while(a && l < r){
        a--;
        l++;
    }
    if (r < l)
    while(a && r < l){
        a--;
        r++;
    }
    if(l == r)
    while(a >= 2){
        a-=2;
        r++;
        l++;
    }
    cout << min(l,r) * 2;
}