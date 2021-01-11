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

const int N = 2e5 + 10, M = 55, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll a[N], b[N], c[N];

int main(){
    init();

    int n, k;   cin >> n >> k;
    for(int i = 0;i < n;i++)    cin >> a[i];
    partial_sum(a, a + n, a);
    for(int i = 0;i < n - k + 1;i++)    b[i] = a[i + k - 1] - ((i) ? a[i - 1] : 0);
    for(int i = n - k;i >= 0;i--)   c[i] = max(b[i], c[i + 1]);

    ll bestSum = 0, start;
    for(int i = 0;i < n - 2 * k + 1;i++){
        ll sum = b[i] + c[i + k];
        if(sum > bestSum){
            start = i;
            bestSum = sum;
        }
    }

    for(int i = start + k;i < n - k + 1;i++)
        if(bestSum - b[start] == b[i])
            return cout << start + 1 << " " << i + 1, 0;
}