#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 35000 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], freq[N];

deque<int> indices[N];

int curL = 0, curR = -1;

ll totalCost;

void update(int type, int x){
    if(indices[x].empty())  return;
    totalCost +=  type * ((indices[x].back() + 1) - (indices[x].front() + 1));
}

void add(int idx) {
    int x = a[idx];

    update(-1, x);

    if(indices[x].empty() || idx > indices[x].back())
        indices[x].push_back(idx);
    else
        indices[x].push_front(idx);

    update(1, x);
}

void remove(int idx) {
    int x = a[idx];

    update(-1, x);

    if(indices[x].size()) {
        if (idx == indices[x].back())
            indices[x].pop_back();
        else
            indices[x].pop_front();
    }

    update(1, x);
}

ll calcCost(int i, int j){
    while (curL > i) add(--curL);
    while (curR < j) add(++curR);
    while (curL < i) remove(curL++);
    while (curR > j) remove(curR--);
    return totalCost;
}

ll dp[N][105];

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

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for(int i = 0;i < n;i++){
        dp[i][1] = calcCost(i, n - 1);
    }

    for(int j = 2;j <= k;j++){
        solve(j, 0, n - j, 0, n - j);
    }

    cout << dp[0][k];
}