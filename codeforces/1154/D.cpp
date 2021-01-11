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
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();

    int n,b,a;
    cin >> n >> b >> a;

    int s[n];
    for(int i = 0;i < n;i++)
        cin >> s[i];

    int capacity = a;

    int mx = 0;
    for(int i = 0;i < n;i++){

        if(s[i] == 0){
            if(a)
                a--;
            else if(b)
                b--;
            else break;
            mx++;
        }

        if(s[i] == 1){
            if(b && a < capacity){
                b--;
                a++;
            }
            else if(a){
                a--;
            }
            else if(b){
                b--;
            }
            else break;
            mx++;
        }
    }

    cout << mx;
}