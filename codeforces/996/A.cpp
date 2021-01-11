#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n;
    cin >> n;
    int oneh = n/100;
    n %= 100;
    int twen = n/20;
    n %= 20;
    int ten = n / 10;
    n %= 10;
    int fiv = n / 5;
    n %= 5;
    cout << oneh + twen + ten + fiv + n;
}