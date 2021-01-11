#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int a, b;   cin >> a >> b;
    if(a == b)  cout << "Draw";
    else if(b != 1 && (a == 1 || (a > b))) cout << "Alice";
    else if(b == 1 || b > a)    cout << "Bob";
}
