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

const int N = 1e6 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, parent[N], sz[N];

struct DSU{
    int components, mxcomponent;
    DSU(){
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
        components = n;
        mxcomponent = 1;
    }

    int find(int u){
        return (parent[u] == u) ? u : parent[u] = find(parent[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v)  return;

        if(sz[u] > sz[v])   swap(u ,v);

        parent[u] = v;
        sz[v] += sz[u];

        components--;
        mxcomponent = max(mxcomponent, sz[v]);
    }


    bool isInSameGroup(int u, int v){
        return find(u) == find(v);
    }

    int getSize(int u){
        return sz[find(u)];
    }
};

int edges[N];

int main(){
    init();

    int m;   cin >> n >> m;
    int a[m], b[m];
    DSU network;
    for(int i = 0;i < m;i++){
        int a, b;   cin >> a >> b;    a--, b--;
        edges[a]++, edges[b]++;
        network.join(a, b);
    }

    for(int i = 0;i < n;i++){
        if(network.getSize(i) != edges[i] + 1)
            return cout << "NO", 0;
    }

    cout << "YES";
}