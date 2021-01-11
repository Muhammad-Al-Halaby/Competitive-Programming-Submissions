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

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n, m;   cin >> n >> m;

    int mn = min(n, m);

    cout << mn + 1 << '\n';
    for(int i = 0;i <= mn;i++){
        cout << i << " " << mn - i << '\n';
    }

}