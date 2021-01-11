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

const int N = 1e3 + 5, M = 2e3 + 5, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], color[M], visited[M];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    color[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}


set<int> ans;
int vid;
int goal;

void dfs(int u, int co){
    if(u == goal){
        ans.insert(co);
        return;
    }

    for(int k = head[u]; ~k ; k = nxt[k]){
        int v = to[k];
        int c = color[k];

        if(visited[k] == vid)   continue;

        if(co == -1 || c == co){
            visited[k] = vid;
            visited[k ^ 1] = vid;
            dfs(v, c);
        }
    }
}

int m, u, v, c;

int main(){
    init();

    cin >> n >> m;
    initGraph();

    for(int i = 0;i < m;i++){
        cin >> u >> v >> c;
        --u, --v;
        addBiEdge(u, v, c);
    }

    int q;  cin >> q;
    for(int i = 0;i < q;i++){
        cin >> u >> v;
        --u, --v;
        goal = v;
        vid++;
        ans.clear();
        dfs(u, -1);
        cout << ans.size() << '\n';
    }
}