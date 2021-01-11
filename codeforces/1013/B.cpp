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
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int fr[(int) 1e5 + 5];
int froffr[(int) 1e5 + 5];

int main(){
    init();

    int n, x;   cin >> n >> x;

    int arr[n];
    set<int> s1,s2;
    loop(i,0,n){
        cin >> arr[i];
        if(s1.find(arr[i]) != s1.end())
            return cout << 0, 0;
        else s1.insert(arr[i]);
    }

    int ans = 3;
    loop(i,0,n){
        int y = x & arr[i];
        if(y == arr[i] || s1.find(y) == s1.end())
            if(s2.find(y) != s2.end())
                ans = min(ans, 2);
            else s2.insert(y);
        else ans = 1;
    }

    if(ans == 3) ans = -1;

    cout << ans;
}