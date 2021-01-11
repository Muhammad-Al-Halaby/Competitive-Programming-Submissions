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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, s;   cin >> n >> s;

    if(s < 2 * n)   return cout << "NO", 0;

    cout << "YES\n";

    cout << s - 2 * (n - 1) << " ";
    for(int i = 0;i < n - 1;i++)    cout << 2 << " ";

    cout << "\n1";
}