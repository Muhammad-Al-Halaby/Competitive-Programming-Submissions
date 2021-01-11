#include<bits/stdc++.h>

using namespace std;
int main(){
    int d1,d2,d3,d;
    cin >> d1 >> d2 >> d3;
    d=0;
    d += min(d1,d2);
    d += min(d1+d2,d3);
    d += min(max(d1,d2),d3+min(d1,d2));
    cout << d;
}