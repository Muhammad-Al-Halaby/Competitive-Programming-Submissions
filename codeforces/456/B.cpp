#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string n;   cin >> n;   n = "0" + n;
    int sz = n.size();

    int x = (n[sz - 1] - '0') + 10 * (n[sz - 2] - '0');
    if(x % 4)   return cout << 0, 0;
    cout << 4;
}