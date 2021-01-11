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

const int N = 1e2 + 5;

int freq[N];

int main(){
    init();

    int n, m;   cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        int success = 0, totalTimeLeft = m - x;
        for(int i = 1;i <= 100;i++){
            int l = 0, r = freq[i];
            while(l <= r){
                int mid = (l+r) >> 1;
                if(mid * i <= totalTimeLeft)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            success += r;
            totalTimeLeft -= r * i;
        }
        cout << i - success << " ";
        freq[x]++;
    }
}