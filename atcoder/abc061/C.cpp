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

const int N = 109, M = 509, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int fr[N];

int main(){
    init();

    ll n, k;   cin >> n >> k;
    pii a[n];
    for(int i = 0;i < n;i++)    cin >> a[i].F >> a[i].S;

    sort(a, a + n);

    for(int i = 0;i < n;i++){
        k -= a[i].S;
        if(k <= 0) return cout << a[i].F, 0;
    }
}