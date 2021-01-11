#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int n, ne, head[N], nxt[M], to[M], vis[M], vid;

ll freq[M], cost[M];

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


ll dfs(int u, int p){
    ll ret = 0;
    for(int k = head[u];~k;k = nxt[k]){
        if(vis[k] != vid){
            freq[k] = freq[k ^ 1] = 0;
            vis[k] = vis[k^1] = vid;
        }
        int v = to[k];
        if(v == p)  continue;

        ll x = dfs(v, u);
        freq[k] += x;
        freq[k^1] += x;

        ret += x;
    }

    if(ret == 0)    ret++;

    return ret;
}


ll s;
ll u, v, c;
void go(int tc = 0){
    cin >> n >> s;

    initGraph();

    vid++;

    for(int i = 0;i < n-1;i++){
        cin >> u >> v >> c;
        u--, v--;
        addBiEdge(u, v, c);
    }

    dfs(0, -1);

    ll sum = 0;
    multiset<pair<ll, int>> vals;
    for(int i = 0;i < ne;i += 2){
        sum += cost[i] * freq[i];
        vals.insert({cost[i] * freq[i] - (cost[i]/2) * freq[i], i});
    }

    ll cnt = 0;
    while(sum > s){
        auto it = vals.end();
        it--;

        pair<ll, int> e = *it;
        int i = e.second;
        sum -= e.first;
        vals.erase(it);

        cost[i] /= 2;

        vals.insert({cost[i] * freq[i] - (cost[i]/2) * freq[i], i});
        cnt++;
    }

    cout << cnt << '\n';
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}