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

const int N = 2005, M = 26, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    char a, b;  cin >> a >> b;
    if((a == 'H' && b == 'H') || (a == 'D' && b == 'D'))
        cout << 'H';
    else
        cout << 'D';
}
