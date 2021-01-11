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

const int N = 2e5 + 9, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;

struct DSU{
    int parent[N], sz[N];
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

int k, l, u, v;

int main(){
    init();

    cin >> n >> k >> l;

    DSU roads, railways;
    for(int i = 0;i < k;i++){
        cin >> u >> v;  u--, v--;
        roads.join(u, v);
    }

    for(int i = 0;i < l;i++){
        cin >> u >> v; u--, v--;
        railways.join(u, v);
    }

    map<pii, int> roots;
    for(int i = 0;i < n;i++){
        int u = roads.find(i);
        int v = railways.find(i);
        roots[{u, v}]++;
    }

    for(int i = 0;i < n;i++){
        int u = roads.find(i);
        int v = railways.find(i);
        cout << roots[{u, v}] << " ";
    }

}
