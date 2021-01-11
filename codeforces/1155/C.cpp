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
#define     S second
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

int main(){
    init();
    int n, m;   cin >> n >> m;
    ll arr[n], mn = LLONG_MAX, gcd = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }

    sort(arr, arr + n);
    for(int i = 1;i < n;i++)
        gcd = __gcd(gcd, abs(arr[i] - arr[i - 1]));

    int j = -1;
    for(int i = 0;i < m;i++){
        ll x;   cin >> x;
        if(gcd % x == 0)
            j = i;
    }

    if(~j)
        cout << "YES\n" << mn << " " << j + 1;
    else
        cout << "NO";
}