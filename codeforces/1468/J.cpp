#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const ll MAX = 2e5 + 5;

struct DSU {
    ll parent[MAX];
    ll groupSize[MAX];
    ll rank[MAX];
    ll CC;

    DSU() {
        CC = MAX;
        for (ll i = 0; i < MAX; ++i) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    ll findLeader(ll node) {
        if (parent[node] == node)return node;
        return parent[node] = findLeader(parent[node]);
    }

    ll sameGroup(ll i, ll j) {
        return findLeader(i) == findLeader(j);
    }

    ll mergeGroup(ll i, ll j) {
        ll leader1 = findLeader(i);
        ll leader2 = findLeader(j);
        if (leader1 == leader2)return 0;
        CC--;
        if (groupSize[leader1] > groupSize[leader2]) {
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        } else {
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];

        }
        return 1;
    }

    void mergeGroupByRank(ll i, ll j) {
        ll leader1 = findLeader(i);
        ll leader2 = findLeader(j);
        if (leader1 == leader2)return;
        if (rank[leader1] < rank[leader2])swap(leader1, leader2);
        parent[leader2] = leader1;
        if (rank[leader1] == rank[leader2])rank[leader1]++;
        CC--;


    }

    ll getCC() {
        return CC;
    }

    ll getSize(ll node) {
        return groupSize[findLeader(node)];
    }
};

struct edge {
    ll w, from, to;

    bool operator<(const edge &e) const {
        return e.w < w;
    }
};

vector<edge> edgList;
ll n, m;
vector<edge> edges, non;

ll kruskal() {
    DSU d;
    ll total = 0;
    priority_queue<edge> q;
    for (ll i = 0; i < edgList.size(); ++i) {
        q.push(edgList[i]);
    }
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (d.mergeGroup(e.from, e.to)) {
            total += e.w;
            edges.push_back(e);
        } else non.push_back(e);
    }

    if (edges.size() != n - 1)return 1e9;
    return total;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> n >> m >> k;
        edges.clear();
        edgList.clear();
        non.clear();
        for (ll i = 0; i < m; ++i) {
            ll u, v, c;
            cin >> u >> v >> c;
            edgList.push_back({c, u, v});
        }
        kruskal();
        ll ans = 1e18;
        if (edges.back().w >=k ) {
            ans = 0;
            for (int i = 0; i < edges.size(); ++i) {
                if (edges[i].w >= k)ans += (edges[i].w - k);
            }
        } else {
            for (int i = 0; i < edgList.size(); ++i) {
                ans = min(ans, abs(k - edgList[i].w
                ));
            }
        }
        cout << ans << "\n";
    }
}