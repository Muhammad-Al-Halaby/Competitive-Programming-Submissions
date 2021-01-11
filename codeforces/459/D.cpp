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
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 1e6 + 9, M = 1e4 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll t[4 * N], a[N];

void build(int v, int s, int e){
    if(s == e)
        return t[v] = a[s], void();

    int mid = (s + e) / 2;
    build(2 * v, s, mid);
    build(2 * v + 1, mid + 1, e);

    // sum
    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(int v, int s, int e, int i){
    if(s == e)
        // value update
        return t[v] = --a[i], void();

    int mid = (s + e) / 2;
    if(i <= mid)
        update(2 * v, s, mid, i);
    else
        update(2 * v + 1, mid + 1, e, i);

    // sum
    t[v] = t[2 * v] + t[2 * v + 1];
}

ll query(int v, int s, int e, int l, int r){
    //  return proper value
    if(l > e || r < s)  return 0;

    if(s >= l && e <= r)
        return t[v];

    int mid = (s + e) / 2;
    ll v1 = query(v * 2, s, mid, l, r);
    ll v2 = query(v * 2 + 1, mid + 1, e, l, r);

    // sum
    return v1 + v2;
}

int main(){
    init();

    int n;  cin >> n;
    int arr[n], pre[n], suf[n];
    map<int,int> mp;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        pre[i] = ++mp[arr[i]];
    }

    mp.clear();
    for(int i = n - 1;~i;i--)
        suf[i] = ++mp[arr[i]];

    for(int i = 0;i < n;i++)
        a[suf[i]]++;

    build(1, 0, n);

    ll ans = 0;
    for(int i = 0;i < n;i++){
        update(1, 0, n, suf[i]);
        ans += query(1, 0, n, 1, pre[i] - 1);
    }

    cout << ans;

}