#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], freq[N];

int curL = 0, curR = -1;

ll totalCost;

void add(int idx) {
    totalCost += freq[a[idx]];
    freq[a[idx]]++;
}

void remove(int idx) {
    freq[a[idx]]--;
    totalCost -= freq[a[idx]];
}

ll calcCost(int i, int j){
    while (curR < j) add(++curR);
    while (curR > j) remove(curR--);
    while (curL < i) remove(curL++);
    while (curL > i) add(--curL);
    return totalCost;
}

ll dp[N][25];

void solve(int k, int l, int r, int optl, int optr){
    if(l > r)   return;

    int mid = (l + r) >> 1;

    ll bestCost = llOO;
    int opt;

    int optlLimit = max(mid, optl);
    for(int i = optlLimit;i <= optr;i++){
        ll cost = calcCost(mid, i) + (i + 1 < n ? dp[i + 1][k - 1] : 0);

        if(cost < bestCost){
            bestCost = cost;
            opt = i;
        }
    }

    dp[mid][k] = bestCost;

    solve(k, l, mid - 1, optl, opt);
    solve(k, mid + 1, r, opt, optr);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n;i++){
        dp[i][1] = calcCost(i, n - 1);
    }

    for(int j = 2;j <= k;j++){
        solve(j, 0, n - j, 0, n - j);
    }

    cout << dp[0][k];
}