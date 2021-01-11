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

const int N = 4e5 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n, k;   cin >> n >> k;  n++;

    ll v[n], sum = n, diff = 3;
    v[1] = n;
    for(int i = 2;i <= (n / 2);i++){
        sum += (n - diff);
        diff += 2;
        v[i] = sum % modulo;
      	sum %= modulo;
    }

    for(int i = k;i <= n;i++)
        if(i > (n / 2))    v[i] = v[n - i];
    v[n] = 1;


    ll ans = 0;
    for(int i = k;i <= n;i++){
        ans += v[i];
        ans %= modulo;
    }

    cout << ans;
}