#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int in[N];

vector<int> adj[N];

int dfs(int u){
    int ret = 1;
    for(auto v : adj[u]){
        ret += dfs(v);
    }
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        for (int j = 0; j < n; j++) {
            cin >> x;
            x--;
            if (j == 0) {
                y = x;
                continue;
            }
            mp[{y, x}]++;
            y = x;
        }
    }


    for (auto &p : mp) {
        if (p.second == m) {
            adj[p.first.first].push_back(p.first.second);
            in[p.first.second]++;
        }
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        if(in[i])   continue;
        ll ret = dfs(i);
        ans += ret * (ret + 1) / 2;
    }
    cout << ans;
}