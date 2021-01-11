#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 3e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int a, b;   cin >> a >> b;
    for(int i = 1;i <= 1000;i++){
        if(int(i * 0.08) == a && int(i * 0.1) == b)   return cout << i, 0;
    }

    cout << -1;
}