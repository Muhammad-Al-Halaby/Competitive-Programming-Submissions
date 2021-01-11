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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 1e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;

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

int color[N];

vector<int> a, b;

int visited[N];
void dfs(int u){

    visited[u] = 1;

    if(head[u] == -1)
        return;

    if(color[u])
        a.PB(u);
    else
        b.PB(u);


    for(int k = head[u]; ~k ; k = nxt[k]){
        int v = to[k];
        if(color[v] == color[u]){
            cout << -1;
            exit(0);
        }

        if(!visited[v]){
            color[v] = !color[u];
            dfs(v);
        }
    }
}



int m, u, v;

int main(){
    init();

    cin >> n >> m;

    initGraph();

    while(m--){
        cin >> u >> v;
        --u, --v;
        addBiEdge(u, v);
    }

    memset(color, -1, sizeof color);

    for(int i = 0;i < n;i++){
        if(!visited[i]){
            color[i] = 0;
            dfs(i);
        }
    }

    cout << a.size() << '\n';
    for(int i = 0;i < a.size();i++)
        cout << a[i] + 1 << " ";

    cout << '\n' << b.size() << '\n';
    for(int i = 0;i < b.size();i++)
        cout << b[i] + 1 << " ";

}