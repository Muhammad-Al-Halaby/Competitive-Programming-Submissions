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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int t1[4 * N], a[N];
pii t2[4 * N];

void build1(int v, int s, int e){
    if(s == e)  return t1[v] = a[s], void();

    int mid = (s + e) / 2;
    build1(2 * v, s, mid);
    build1(2 * v + 1, mid + 1, e);

    t1[v] = __gcd(t1[2 * v], t1[2 * v + 1]);
}

void build2(int v, int s, int e){
    if(s == e)  return t2[v] = {a[s], 1}, void();

    int mid = (s + e) / 2;
    build2(2 * v, s, mid);
    build2(2 * v + 1, mid + 1, e);

    if(t2[2 * v].F == t2[2 * v + 1].F)
        return t2[v] = {t2[2 * v].F, t2[2 * v].S + t2[2 * v + 1].S}, void();
    else if(t2[2 * v].F < t2[2 * v + 1].F)
        return t2[v] = {t2[2 * v].F, t2[2 * v].S}, void();
    return t2[v] = {t2[2 * v + 1].F, t2[2 * v + 1].S}, void();
}

int query1(int v, int s, int e, int l, int r){
    if(r < s || l > e)  return 0;

    if(s >= l && e <= r)
        return t1[v];

    int mid = (s + e) / 2;
    int v1 = query1(v * 2, s, mid, l, r);
    int v2 = query1(v * 2 + 1, mid + 1, e, l, r);

    return __gcd(v1, v2);
}

pii query2(int v, int s, int e, int l, int r){
    if(r < s || l > e)  return {OO, 0};

    if(s >= l && e <= r)
        return t2[v];

    int mid = (s + e) / 2;
    pii v1 = query2(v * 2, s, mid, l, r);
    pii v2 = query2(v * 2 + 1, mid + 1, e, l, r);

    if(v1.F == v2.F)
        return {v1.F, v1.S + v2.S};
    else if(v1.F < v2.F)
        return {v1.F, v1.S};
    return {v2.F, v2.S};
}

int n, m;

int main(){
    init();

    cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];

    build1(1, 0, n - 1);   build2(1, 0, n - 1);

    cin >> m;
    for(int i = 0;i < m;i++){
        int l, r;   cin >> l >> r;  l--, r--;
        int gcd = query1(1, 0, n - 1, l, r);
        pii mn = query2(1, 0, n - 1, l, r);
        if(gcd == mn.F){
            cout << (r - l + 1) - mn.S << '\n';
        }
        else cout << r - l + 1 << '\n';
    }
}