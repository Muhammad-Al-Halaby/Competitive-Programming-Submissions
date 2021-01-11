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

    string a, b;    cin >> a >> b;
    int n = a.size(), m = b.size();

    int z[m];
    for(int i = 0;i < m;i++){
        z[i] = b[i] == '0';
        if(i)   z[i] += z[i - 1];
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] == '0')
            ans += (m - n + 1) - (z[m - n + i] - (i ? z[i - 1] : 0));
        else
            ans += z[m - n + i] - (i ? z[i - 1] : 0);
    }

    cout << ans;
}