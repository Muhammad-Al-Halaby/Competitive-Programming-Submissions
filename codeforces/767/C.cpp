#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("meciul.in","r",stdin);
    freopen("meciul.out","w",stdout);
#endif
}



const int N = 1e6 + 5, M = 2e6 + 6, OO = 0x3f3f3f3f;

int n, ne, head[N], nxt[M], to[M], temp[N];

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

vector<int> good;

int root, s;

int dfs(int u, int p){
    ll total = temp[u];
    for(int k = head[u]; ~k ; k = nxt[k]){
        int v = to[k];
        if(v != p)
            total += dfs(v, u);
    }

    if(u != root && total == s / 3){
        total = 0;
        good.PB(u);
    }
    return total;
}


int u, v;

int main(){
    init();

    cin >> n;
    initGraph();
    for(int i = 0;i < n;i++){
        cin >> u >> v;  --u;
        if(u != -1)  addBiEdge(i, u);
        else root = i;
        temp[i] = v;
        s += v;
    }

    if(s % 3)
        return puts("-1"), 0;

    dfs(root, -1);

    if(good.size() >= 2)
        cout << good[0] + 1 << " " << good[1] + 1;
    else
        puts("-1");
}