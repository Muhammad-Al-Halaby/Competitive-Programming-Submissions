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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 600, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();
    int n, q;   cin >> n >> q;
    int painted[n + 2] = {0}, one[n + 2] = {0};
    pii ranges[q];
    for(int i = 0;i < q;i++){
        int l, r;   cin >> l >> r;
        ranges[i].F = l, ranges[i].S = r;
        painted[l]++;
        painted[r+1]--;
    }


    partial_sum(painted, painted + n + 2, painted);

    int totalPainted = 0;
    for(int i = 1;i <= n;i++)   totalPainted += (painted[i] > 0);

    int ans = 0;
    for(int i = 0;i < q;i++){
        int cnt = totalPainted;
        
        int l = ranges[i].F, r = ranges[i].S;
        for(int j = l;j <= r;j++){
            painted[j]--;
            cnt -= (painted[j] == 0);
        }
        
        for(int i = 1;i <= n;i++)   one[i] = (painted[i] == 1) + one[i - 1];
        
        for(int j = i + 1;j < q;j++){
            int x = ranges[j].F, y = ranges[j].S;
            ans = max(ans, cnt - (one[y] - one[x - 1]));
        }
        
        for(int j = l;j <= r;j++)   painted[j]++;
    }

    cout << ans;
}