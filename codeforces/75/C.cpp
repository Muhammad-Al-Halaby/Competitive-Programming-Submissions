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

bool in_range(ll x, ll l, ll r){
    return x >= l && x <= r;
}

int main(){
    init();

    int a, b, q, mx;   cin >> a >> b >> q;

    mx = max(a, b);

    set<int> divCommon;
    for(int i = 1;i * i <= mx;i++){
        if(a % i == 0 && b % i == 0)
            divCommon.insert(i);
        if(a % i == 0)
            if(b % (a / i) == 0)
                divCommon.insert(a / i);
        if(b % i == 0)
            if(a % (b / i) == 0)
                divCommon.insert(b / i);
    }

    vector<int> div(divCommon.begin(), divCommon.end());

    while(q--){
        int lq, rq;   cin >> lq >> rq;

        int l = 0, r = div.size() - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(in_range(div[mid], lq, rq) || div[mid] < lq){
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        cout << (in_range(div[l - 1], lq, rq) ? div[l - 1] : -1) << '\n';
    }
}