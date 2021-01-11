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

const int N = 1e4 + 9;

int n, q;
string s;
int prefix[26][N];
int best[26][N];


int main(){
    init();

    cin >> n >> s;

    for(int i = 0;i < n;i++)
        prefix[s[i] - 'a'][i]++;

    for(int i = 0;i < 26;i++)
        for(int j = 1;j < n;j++)
            prefix[i][j] += prefix[i][j - 1];

    for(int c = 0;c < 26;c++){
        for(int m = 1;m <= n;m++){
            for(int i = 0;i < n;i++){
                int l = i, r = n - 1;
                while(l <= r){
                    int mid = (l + r + 1) >> 1;
                    int change = (mid - i + 1) - (prefix[c][mid] - ((i == 0) ? 0 : prefix[c][i - 1]));
                    if(change <= m)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }

                best[c][m] = max(best[c][m], r - i + 1);
            }
        }
    }

    cin >> q;

    for(int i = 0;i < q;i++){
        int m; char c;  cin >> m >> c;
        cout << best[c - 'a'][m] << '\n';
    }
}