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

    string o, e;    cin >> o >> e;

    int p1, p2; p1 = p2 = 0;
    for(int i = 1;i <= o.size() + e.size();i++){
        if(i & 1)
            cout << o[p1++];
        else
            cout << e[p2++];
    }
}