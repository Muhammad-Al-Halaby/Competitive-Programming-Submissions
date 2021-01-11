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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;

    if(n <= 2)  return cout << "1\n1", 0;
    if(n == 3)  return cout << "2\n1 3", 0;

    cout << n << '\n';
    for(int i = (n & 1 ? n : n - 1);i >= 1;i -= 2) cout << i << " ";
    for(int i = (n & 1 ? n - 1 : n);i >= 1;i -= 2) cout << i << " ";
}