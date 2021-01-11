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


int main(){
    init();

    int w,h,n;  cin >> w >> h >> n;
    int arr[4] = {0,w,0,h};
    for(int i = 0;i < n;i++){
        int x,y,a;  cin >> x >> y >> a;
        if(a == 1)
            arr[0] = max(arr[0], x);
        else if(a == 2)
            arr[1] = min(arr[1], x);
        else if(a == 3)
            arr[2] = max(arr[2], y);
        else
            arr[3] = min(arr[3], y);
    }

    if(arr[0] > arr[1] || arr[2] > arr[3])
        return cout << 0, 0;

    cout << abs(arr[0] - arr[1]) * abs(arr[2] - arr[3]);
}