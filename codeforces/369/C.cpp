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
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e5+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int n, ne, head[N], nxt[M], to[M], state[M];

void initGraph(){
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}

void addEdge(int f, int t, int s){
    to[ne] = t;
    state[ne] = s;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int u, int v, int s){
    addEdge(u, v, s);
    addEdge(v, u, s);
}

set<int> ans;

int dfs(int u, int p){
    int ret = u;
    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];  if(v == p)  continue;
        int t = state[k];
        int candidate = dfs(v, u);
        if(t)    ans.insert(candidate);
        if(t || candidate != v)  ret = candidate;
    }

    return ret;
}

int main(){
    init();

    cin >> n;   initGraph();

    for(int i = 0;i < n - 1;i++){
        int x, y, t;    cin >> x >> y >> t; --x, --y, --t;
        addBiEdge(x, y, t);
    }

    dfs(0, 0);

    cout << ans.size() << '\n';
    for(auto v : ans)
        cout << v + 1 << " ";
}