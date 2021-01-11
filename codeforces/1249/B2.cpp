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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 2e5+5, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}



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

int main(){
    init();

    int q;  cin >> q;
    while(q--){
        cin >> n;
        DSU kids;
        for(int i = 0;i < n;i++){
            int x;  cin >> x;   x--;
            kids.join(i, x);
        }

        for(int i = 0;i < n;i++)
            cout << kids.getSize(i) << " ";
        cout << '\n';
    }
}