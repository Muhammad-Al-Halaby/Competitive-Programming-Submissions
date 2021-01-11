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


int powers[32];

int count_powers(){
    return accumulate(powers, powers + 32, 0);
}
int main(){
    init();
    int n, k;
    cin >> n >> k;
    vector<int> twos;
    for(int i = 0;i < 32;i++){
        if((1 << i) & n)
            powers[i]++;
    }

    int cnt = count_powers();

    while(cnt < k){
        for(int i = 1;i < 32;i++){
            if(cnt >= k)break;
            if(powers[i]){
                cnt += 1;
                powers[i]--;
                powers[i - 1] += 2;
            }
        }

        if(cnt == powers[0])break;
    }

    if(count_powers() != k)
        return cout << "NO", 0;

    cout << "YES\n";

    for(int i = 0;i < 32;i++){
        for(int j = 0;j < powers[i];j++)
            cout << (1 << i) << " ";
    }
}