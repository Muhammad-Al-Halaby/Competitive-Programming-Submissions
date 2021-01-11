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

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, t;   cin >> n >> t;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    int mx = 0, mxProfit = 0;
    for(int i = n - 1;i >= 0;i--){
        mxProfit = max(mxProfit, mx - a[i]);
        mx = max(mx, a[i]);
    }


    map<int, int> mp;
    int ans = 0;
    for(int i = n - 1;i >= 0;i--){
        ans += mp.count(a[i] + mxProfit);
        mp[a[i]]++;
    }

    cout << ans;
}