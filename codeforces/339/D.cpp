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

const int N = 1e6 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int t[4 * N], a[N];

void build(int v, int s, int e, bool op){
    if(s == e)
        return t[v] = a[s], void();

    int mid = (s + e) / 2;
    build(2 * v, s, mid, op ^ 1);
    build(2 * v + 1, mid + 1, e, op ^ 1);

    // operation
    if(op)
        t[v] = t[2 * v] | t[2 * v + 1];
    else
        t[v] = t[2 * v] ^ t[2 * v + 1];
}

void update(int v, int s, int e, int &i, int &val, bool op){
    if(s == e)
        // value update
        return t[v] = a[i] = val, void();

    int mid = (s + e) / 2;
    if(i <= mid)
        update(2 * v, s, mid, i, val, op ^ 1);
    else
        update(2 * v + 1, mid + 1, e, i, val, op ^ 1);

    // operation
    if(op)
        t[v] = t[2 * v] | t[2 * v + 1];
    else
        t[v] = t[2 * v] ^ t[2 * v + 1];
}

int query(int v, int s, int e, int &l, int &r){
    //  return proper value
    if(l > e || r < s)  return OO;

    if(s >= l && e <= r)
        return t[v];

    int mid = (s + e) / 2;
    int v1 = query(v * 2, s, mid, l, r);
    int v2 = query(v * 2 + 1, mid + 1, e, l, r);
}

int main(){
    init();

    int n, k, q;  cin >> n >> q;
    k = 1 << n;
    for(int i = 0;i < k;i++)    cin >> a[i];

    build(1, 0, k - 1, n % 2);

    while(q--){
        int p, b;   cin >> p >> b;  p--;
        update(1, 0, k - 1, p, b, n % 2);

        int l = 0, r = k - 1;
        cout << query(1, 0, k - 1, l, r) << '\n';
    }
}