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

const int N = 109, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], cost[M];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}

int dist[N];
map<pii, int> edges;

void dijkstraSparse(int src){
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    priority_queue<pair<int, pii>> q;
    q.push({0, {src, -1}});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second.first;
        src = q.top().second.second;
        q.pop();
        if(d != dist[u])    continue;

        if(~src) edges[{min(u ,src), max(u, src)}] = 1;

        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            int dd = d + cost[e];
            if(dist[v] > dd){
                dist[v] = dd;
                q.push({-dd, {v, u}});
            }
        }
    }
}

int m, u, v, c;

int main(){
    init();

    cin >> n >> m;  initGraph();

    for(int i = 0;i < m;i++){
        cin >> u >> v >> c;  --u, --v;
        addBiEdge(u, v, c);
    }

    for(int i = 0;i < n;i++)    dijkstraSparse(i);

    cout << m - edges.size();
}