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

int n;
string st;

struct node{
    int open = 0, close = 0, good = 0;

    node(){}

    node(char b){
        if(b == '(')    open++;
        else close++;
    }

    node(int o, int c, int g){
        open = o;
        close = c;
        good = g;
    }
};

node t[4 * N];

void build(int v, int s, int e){
    if(s == e)
        return t[v] = node(st[s]), void();

    int mid = (s + e) / 2;

    build(v * 2 + 1, s, mid);
    build(v * 2 + 2, mid + 1, e);

    node &l = t[2 * v + 1];
    node &r = t[2 * v + 2];

    int mn = min(l.open, r.close);
    int good = l.good + 2 * min(l.open, r.close) + r.good;

    t[v] = node(l.open + r.open - mn, l.close + r.close - mn, good);
}

node query(int v, int s, int e, int l, int r) {
    if(r < s || l > e)
        return node(0, 0, 0);

    if(l <= s && r >= e)
        return t[v];

    int mid = (s + e) / 2;

    node lf = query(2 * v + 1, s, mid, l, r);
    node rg = query(2 * v + 2, mid + 1, e, l, r);

    int mn = min(lf.open, rg.close);
    int good = lf.good + 2 * min(lf.open, rg.close) + rg.good;

    return node(lf.open + rg.open - mn, lf.close + rg.close - mn, good);
}

void go(int tc = 0){
    cin >> st;

    n = st.size();

    build(0, 0, n - 1);

    int q;  cin >> q;
    while(q--){
        int l, r;   cin >> l >> r;
        --l, --r;
        cout << query(0, 0, n - 1, l, r).good << '\n';
    }
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)
        go(tc++);
}