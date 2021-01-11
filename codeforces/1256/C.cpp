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

const int N = 2e5+5, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    //res %= modulo;
    if(p & 1)res *= b;
    return res;// % modulo;
}

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

int main(){
    init();

    int n, m, d;    cin >> n >> m >> d;
    int arr[n+2] = {0}, c[m+1];
    for(int i = 1;i <= m;i++)
        cin >> c[i];

    for(int j = m, i = n;j;--j){
        int x = c[j];
        while(x--)    arr[i--] = j;
    }

    int pos = 0, cn = 1, ok = 1;
    while(cn <= m){
        int mxJMP = pos + d, start;

        for(int i = 1;i <= n;i++){
            if(arr[i] == cn){
                start = i;
                break;
            }
        }

        if(mxJMP < start){
            for(int i = start;arr[i] == cn;i++)
                arr[i] = 0;

            for(int i = 0;i < c[cn];i++)
                arr[mxJMP + i] = cn;
        }

        for(int i = pos;i <= n;i++)
            if(arr[i] == cn)    pos = i;

        if(cn == m && pos + d < n + 1)  ok = 0;
        cn++;
    }

    if(!ok) return cout << "NO", 0;

    cout << "YES\n";

    for(int i = 1;i <= n;i++)
        cout << arr[i] << " ";
}