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

const int N = 3e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, nxt[N];
vector<pii> seg;

ll dp[N];

ll solve(int i){
    if(i == n)  return 1;

    ll &ret = dp[i];
    if(~ret)    return ret;

    ret = solve(i + 1) + solve(nxt[i]);

    while(ret >= 998244353) ret -= 998244353;

    return ret;
}

int main(){
    init();

    cin >> n;
    for(int i = 0;i < n;i++){
        int x, d;   cin >> x >> d;
        seg.push_back({x, x + d - 1});
    }

    sort(seg.begin(), seg.end());

    for(int i = n - 1;i >= 0;i--){
        int j = i + 1;
        while(j < n && seg[i].S >= seg[j].F)   j = nxt[j];
        nxt[i] = j;
    }


    memset(dp, -1, sizeof dp);

    cout << solve(0);
}