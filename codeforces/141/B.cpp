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

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int a, x, y;    cin >> a >> x >> y;

    if(y % a == 0 || x == a) return cout << -1, 0;

    int box = 0;
    for(int i = 1;i <= 1e6;i++){
        int mx = a * i;
        if(i == 1 || !(i & 1))  box++;
        else box += 2;

        if(y > mx)  continue;
        if(x == 0 && (i != 1 && (i & 1)))   return cout << -1, 0;

        if((i == 1 || !(i & 1)) && abs(x) < a/2.0)    return cout << box, 0;
        if(i > 1 && (i & 1) && x > 0 && abs(x) < a)  return cout << box, 0;
        if(i > 1 && (i & 1) && x < 0 && abs(x) < a)  return cout << box - 1, 0;

        break;
    }

    cout << -1;
}