#include<bits/stdc++.h>
using namespace std; 

int main(){
    int m,d;
    int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> m >> d;
    cout << ceil((months[m]-(8-d))/7.0)+1;
}