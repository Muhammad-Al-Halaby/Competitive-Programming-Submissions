#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 35000 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], freq[N];

vector<int> indices[N];

int leftmostIdx[N], rightmostIdx[N];

int curL = 0, curR = -1;

ll totalCost;

void update(int type, int x){
    int left = (leftmostIdx[x] == -1 || leftmostIdx[x] == (int) indices[x].size() ? -1 : indices[x][leftmostIdx[x]]);
    int right = (rightmostIdx[x] == -1 || rightmostIdx[x] == (int) indices[x].size() ? -1 : indices[x][rightmostIdx[x]]);

    if(left == -1 && right == -1)   return;
    else if(left == -1)  left = right;
    else if(right == -1) right = left;
    if(left > right)    return;

    totalCost += type * (right - left);
}

void add(int idx, int dir) {
    int x = a[idx];

    update(-1, x);

    if(dir == 0) {
        if(rightmostIdx[x] == -1 && leftmostIdx[x] != -1)
            rightmostIdx[x] = leftmostIdx[x];
        leftmostIdx[x]--;
    }
    else{
        if(leftmostIdx[x] == -1 && rightmostIdx[x] != -1)
            leftmostIdx[x] = rightmostIdx[x];
        rightmostIdx[x]++;
    }

    update(1, x);
}

void remove(int idx, int dir) {
    int x = a[idx];

    update(-1, x);

    if(dir == 0) {
        leftmostIdx[x]++;
    }
    else{
        rightmostIdx[x]--;
    }

    update(1, x);
}

ll calcCost(int i, int j){
    while (curL < i) remove(curL++, 0);
    while (curL > i) add(--curL, 0);
    while (curR < j) add(++curR, 1);
    while (curR > j) remove(curR--, 1);
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
        indices[a[i]].push_back(i);
    }

    memset(leftmostIdx, -1, sizeof leftmostIdx);
    memset(rightmostIdx, -1, sizeof rightmostIdx);
    
    for(int i = 0;i < n;i++){
        dp[i][1] = calcCost(i, n - 1);
    }

    for(int j = 2;j <= k;j++){
        solve(j, 0, n - j, 0, n - j);
    }

    cout << dp[0][k];
}