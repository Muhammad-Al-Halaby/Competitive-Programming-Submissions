#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, ne, head[N], nxt[M], to[M];


void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}

int a[N], dist[N], vis[N], vid;

int bfs(int p){
    queue<int> q;
    for(int i = 0;i < n;i++)
        if(a[i] == p){
            q.push(i);
            vis[i] = vid;
        }

    int sz = q.size(), depth = 1;
    for(;sz;sz = q.size(), depth++){
        while(sz--){
            int u = q.front();  q.pop();
            for(int k = head[u]; ~k ; k = nxt[k]){
                int v = to[k];
                if(vis[v] == vid)  continue;
                if(a[v] == !p && dist[v] == -1)  dist[v] = depth;
                vis[v] = vid;
                q.push(v);
            }
        }
    }
}

int main(){
    init();

    memset(dist, -1, sizeof dist);

    cin >> n;
    initGraph();

    for(int i = 0;i < n;i++){
        cin >> a[i];

        if(i + a[i] < n)    addEdge(i + a[i], i);

        if(i - a[i] >= 0)   addEdge(i - a[i], i);


        a[i] = (a[i] & 1);

    }

    vid++;
    bfs(0);
    vid++;
    bfs(1);

    for(int i = 0;i < n;i++)    cout << dist[i] << " ";

}
