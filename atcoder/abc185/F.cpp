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

int n;

ll t[4 * N], a[N];


void build(int v, int l = 0, int r = n - 1){
    if(l == r)
        return t[v] = a[l], void();

    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] ^ t[2 * v + 2];
}

void update(int v, int start, int end, ll val, int l = 0, int r = n - 1){
    if(start <= l && end >= r){
        t[v] ^= val;
        return;
    }

    if(start > r || end < l)  return;

    int mid = (l + r) / 2;
    update(2 * v + 1, start, end, val, l, mid);
    update(2 * v + 2, start, end, val, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] ^ t[2 * v + 2];
}

ll query(int v, int start, int end, int l = 0, int r = n - 1){
    //  return proper value
    if(start > r || end < l)  return 0;

    if(l >= start && r <= end)
        return t[v];

    int mid = (l + r) / 2;
    ll v1 = query(v * 2 + 1, start, end, l, mid);
    ll v2 = query(v * 2 + 2, start, end, mid + 1, r);

    // sum
    return v1 ^ v2;
}

int main() {
    init();

    int q;

    cin >> n >> q;
    memset(::t, 0, sizeof ::t);

    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    build(1);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, --r;
        if (t == 1) {
            update(1, l, l, r + 1);
        } else cout << query(1, l, r) << '\n';
    }

}