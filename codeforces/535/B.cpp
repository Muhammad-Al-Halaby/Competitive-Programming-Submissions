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

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;
    int len = floor(log10(n)) + 1;

    int ans = (1 << len) - 1;
    for(int i = 0;i < (1 << len);i++){
        ll x = 0;
        for(int j = 0;j < len;j++){
            if((i >> j) & 1)    x = x * 10 + 4;
            else x = x * 10 + 7;
        }
        if(x < n)   ans++;
    }

    cout << ans;
}