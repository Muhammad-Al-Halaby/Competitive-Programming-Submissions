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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int a, b, c;    cin >> a >> b >> c;
    for(int i = 0;i <= 1e6;i++){
        if((c + i * b) % a == 0)    return cout << "YES", 0;
    }

    cout << "NO";

}