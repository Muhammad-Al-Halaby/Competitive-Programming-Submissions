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

const int N = 1e5 + 5;
struct DSU{
  int parent[N], sz[N];

  DSU(){
      iota(parent, parent + N, 0);
      fill(sz, sz + N, 1);
  }
  int findParent(int u){
    return (u == parent[u] ? u : parent[u] = findParent(parent[u]));
  }

  void mergeSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b)
        return;

    if(sz[a] < sz[b])swap(a, b);

    parent[b] = parent[a];
    sz[a] += sz[b];
  }
};
int main(){
    init();
    DSU roads;
    int n;  cin >> n;
    for(int i = 0;i < n;i++){
        int p;  cin >> p;   p--;
        roads.mergeSet(i, p);
    }
    set<pii> s;
    for(int i = 0;i < n;i++){
        int p = roads.findParent(i);
        s.insert({roads.sz[p], p});
    }


    vector<int> sz;
    for(auto p : s)
        sz.push_back(p.F);

    ll ans = 0;
    for(int i = 0;i < sz.size();i++){
        if(i + 1 == sz.size() - 1){
            ans += (ll)(sz[i] + sz[i + 1]) * (sz[i] + sz[i + 1]);
            break;
        }
        else
            ans += (ll)sz[i] * sz[i];
    }

    cout << ans;
}