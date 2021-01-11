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
    freopen("meciul.in","r",stdin);
    freopen("meciul.out","w",stdout);
#endif
}
const int N = 1e7;

int n, arr[N], fr[N], dist[N];


void bfs(int n){
    queue<pii> q;
    fr[n]++;
    q.push({n, 0});
    q.push({n, 1});
    int depth = 1, sz = 2;
    for(;q.size();++depth, sz = q.size()){
        while(sz--){
            int v = q.front().F;
            int s = q.front().S;

            q.pop();

            if(s && v * 2 < 1e7){
                int x = v * 2;
                fr[x]++;
                dist[x] += depth;
                q.push({x, s});
            }

            if(!s && v / 2 > 0){
                int x = v / 2;
                fr[x]++;
                dist[x] += depth;
                q.push({x, s});
                if(v & 1)
                    q.push({x, !s});
            }

        }
    }
}
int main(){
    init();
    cin >> n;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        bfs(x);
    }
    int ans = INT_MAX;
    for(int i = 1;i < N;i++){
        if(fr[i] == n)
            ans = min(ans, dist[i]);
    }

    cout << ans;

}