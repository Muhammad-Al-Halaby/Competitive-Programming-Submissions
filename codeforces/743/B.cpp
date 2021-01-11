#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 55, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();
    ll n, k;    cin >> n >> k;
    ll sz[n + 1] = {0};
    for(int i = 1;i <= n;i++)
        sz[i] = sz[i - 1] * 2 + 1;

    int i;
    while(true){
        i = lower_bound(sz, sz + n + 1, k) - sz;;
        if(sz[i - 1] + 1 == k)
            return cout << i, 0;
        k -= (sz[i - 1] + 1);
    }
}