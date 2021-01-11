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
//#define modulo ll (1e9 + 7)
#define modulo ll (1e6 + 3)
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
    string s[] = {"Ciel", "Hanako"};

    int x, y, p = 0;
    cin >> x >> y;

    while(true){
        int f = 0;
        if(p)
            for(int i = 0;i <= 2;i++){
                for(int j = 1;j <= 22;j++){
                    if(i * 100 + j * 10 == 220 && i <= x && j <= y){
                        f = 1;
                        x -= i;
                        y -= j;
                        break;
                    }
                }
                if(f)break;
            }
        else
            for(int i = 1;i <= 22;i++){
                for(int j = 0;j <= 2;j++){
                    if((i * 10 + j * 100) == 220 && i <= y && j <= x){
                        f = 1;
                        x -= j;
                        y -= i;
                        break;
                    }
                }
                if(f)break;
            }
        p ^= 1;
        if(!f)break;
    }

    cout << s[p];
}