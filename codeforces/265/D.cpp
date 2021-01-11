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

const int N = 1e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, a[N], dp[N], dpF[N];

int solve(){
    for(int i = 0;i < n;i++){
        vector<int> divisors;
        for(int j = 1;j * j <= a[i];j++){
            if(a[i] % j) continue;
            if(j != 1)  divisors.push_back(j);
            if(a[i] / j != j)    divisors.push_back(a[i] / j);
        }

        int best = 1;
        for(int j = 0;j < divisors.size();j++)
            best = max(best, 1 + dpF[divisors[j]]);

        dp[i] = best;
        for(int j = 0;j < divisors.size();j++)
            dpF[divisors[j]] = best;
    }

    return *max_element(dp, dp + n);
}

int main(){
    init();

    cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    cout << solve();
}
