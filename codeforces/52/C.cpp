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

const int N = 2e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll t[4 * N], lazy[4 * N], a[N];

void check(int v, int s, int e){
    if(lazy[v]){
        t[v] += lazy[v];
        if(s != e){
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void build(int v, int s, int e){
    check(v, s, e);

    if(s == e)
        return t[v] = a[s], void();

    int mid = (s + e) / 2;
    build(2 * v, s, mid);
    build(2 * v + 1, mid + 1, e);

    // minimum
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void update(int v, int s, int e, int l, int r, ll val){
    check(v, s, e);

    if(s >= l && e <= r){
        t[v] += val;
        if(s != e){
            lazy[v * 2] += val;
            lazy[v * 2 + 1] += val;
        }
        return;
    }

    if(l > e || r < s)  return;

    int mid = (s + e) / 2;
    update(2 * v, s, mid, l, r, val);
    update(2 * v + 1, mid + 1, e, l, r, val);

    // minimum
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

ll query(int v, int s, int e, int l, int r){
    check(v, s, e);

    //  return proper value
    if(l > e || r < s)  return llOO;

    if(s >= l && e <= r)
        return t[v];

    int mid = (s + e) / 2;
    ll v1 = query(v * 2, s, mid, l, r);
    ll v2 = query(v * 2 + 1, mid + 1, e, l, r);

    // minimum
    return min(v1, v2);
}

int main(){
    init();

    int n;  cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    build(1, 0, n - 1);

    int q;  cin >> q;   cin.ignore();
    while(q--){
        string s;   getline(cin, s);
        stringstream ss;    ss << s;
        int l, r, v = OO;
        ss >> l >> r;
        while(ss >> v);
        if(v == OO){
            if(l > r)
                cout << min(query(1, 0, n - 1, 0, r), query(1, 0, n - 1, l, n - 1));
            else
                cout << query(1, 0, n - 1, l, r);
            cout << '\n';
        }
        else{
            if(l > r)
                update(1, 0, n - 1, 0, r, v), update(1, 0, n - 1, l, n - 1, v);
            else
                update(1, 0, n - 1, l, r, v);
        }
    }
}
