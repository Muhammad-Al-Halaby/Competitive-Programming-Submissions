#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])


typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

//typedef vector<ll> row;
//typedef vector<row> matrix;
//
//matrix zero(int n, int m){
//    return matrix(n, row(m, 0));
//}
//
//matrix identity(int n){
//    matrix ret = zero(n, n);
//    for(int i = 0;i < n;i++)    ret[i][i] = 1;
//    return ret;
//}
//
//matrix multiply(const matrix &a, const matrix &b){
//    matrix ret = zero(a.size(), b[0].size());
//    for(int i = 0;i < a.size();i++){
//        for(int k = 0;k < a[0].size();k++){
//            for(int j = 0;j < b[0].size();j++){
//                ret[i][j] += (a[i][k] * b[k][j]) % modulo;
//                ret[i][j] %= modulo;
//            }
//        }
//    }
//    return ret;
//}
//
//matrix power(const matrix &a, ll k){
//    if(k == 0)
//        return identity(a.size());
//
//    if(k % 2 == 1)
//        return multiply(a, power(a, k - 1));
//
//    return power(multiply(a, a), k / 2);
//}
//
//ll power(ll b, ll p, ll mod = 2e18){
//    if(p == 0)return 1;
//    ll res = power(b,p/2, mod);
//    res *= res;
//    res %= mod;
//    if(p & 1)res *= b;
//    return res % mod;
//}

struct Adj {
    int n, ne, head[N], nxt[M], to[M], cost[M];

    void initGraph(int n) {
        memset(head, -1, (n + 1) * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t, int c) {
        to[ne] = t;
        cost[ne] = c;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
} adj;

int k;

ll dfs(int u, int p){
    ll rem = (p == -1 ? k - 1 : k - 2);
    ll ret = (p == -1 ? k : 1);
    neig(adj, u, e, v){
        if(v == p)  continue;
        ret *= rem--;
        ret %= modulo;
        ret *= dfs(v, u);
        ret %= modulo;
    }
    return ret;
}

int main() {
    init();

    int n;   cin >> n >> k;
    adj.initGraph(n);

    for(int i = 0;i < n - 1;i++){
        int u, v;   cin >> u >> v;
        --u, --v;
        adj.addBiEdge(u, v, 0);
    }

    cout << dfs(0, -1);
}