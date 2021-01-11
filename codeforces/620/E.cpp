#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 4e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], color[N];

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

int subtreeStart[N], subtreeEnd[N], cnt;

void dfs(int u, int p){
    subtreeStart[u] = cnt++;
    for(int k = head[u];~k;k = nxt[k]){
        int v = to[k];
        if(v == p)  continue;
        dfs(v, u);
    }
    subtreeEnd[u] = cnt - 1;
}


int root, lazyUpdate[N], nodeColor[N];

ll buckets[N];

int getBucket(int u){
    return u / root;
}

inline ll colorBit(ll c){
    return (1ll << c);
}

void bucketLazy(int u, int v, int c){
    int bucketNumber = getBucket(u);
    int bucketStart = bucketNumber * root;
    buckets[bucketNumber] = 0;
    for(int i = bucketStart;i < bucketStart + root;i++){
        if(i >= u && i <= v)
            nodeColor[i] = c;
        else if(lazyUpdate[bucketNumber] != -1)
            nodeColor[i] = lazyUpdate[bucketNumber];
        buckets[bucketNumber] |= colorBit(nodeColor[i]);
    }
    lazyUpdate[bucketNumber] = -1;
}

int m, u, v, c, b;

int main(){
    init();

    cin >> n >> m;

    initGraph();

    for(int i = 0;i < n;i++)    cin >> color[i];

    for(int i = 0;i < n - 1;i++){
        cin >> u >> v;  --u, --v;
        addBiEdge(u, v);
    }

    dfs(0, -1);

    root = sqrt(n);

    memset(lazyUpdate, -1, sizeof lazyUpdate);

    for(int i = 0;i < n;i++){
        c = color[i];
        u = subtreeStart[i];

        b = u / root;
        buckets[b] |= colorBit(c);
        nodeColor[u] = c;
    }

    while(m--){
        int t;  cin >> t;   t--;

        if(!t){
            //Update
            cin >> u >> c;  u--;
            v = subtreeEnd[u];
            u = subtreeStart[u];

            for(int i = u;i <= v;i++){
                int bucketNumber = getBucket(i);

                // complete bucket
                if(i % root == 0 && i + root - 1 <= v){
                    lazyUpdate[bucketNumber] = c;
                    buckets[bucketNumber] = colorBit(c);
                    i += root - 1;
                    continue;
                }

                //head or tail
                int last = min(v, bucketNumber * root + root - 1);
                bucketLazy(i, last, c);

                i = last;
            }

            continue;
        }


        // Query
        cin >> u;   --u;
        v = subtreeEnd[u];
        u = subtreeStart[u];

        ll ans = 0;
        for(int i = u;i <= v;i++){
            int bucketNumber = getBucket(i);

            // complete bucket
            if(i % root == 0 && i + root - 1 <= v){
                ans |= buckets[bucketNumber];
                i += root - 1;
                continue;
            }

            //head or tail
            if(lazyUpdate[bucketNumber] == -1)
                ans |= colorBit(nodeColor[i]);
            else
                ans |= colorBit(lazyUpdate[bucketNumber]);
        }

        cout << __builtin_popcountll(ans) << '\n';
    }

}