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
    int n, sum = 0;
    cin >> n;
    vector<int> even, odd;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(x & 1)odd.push_back(x);
        else even.push_back(x);
        sum += x;
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int cnt = min(odd.size(), even.size());
    for(int i = 0;i < cnt;i++){
        sum -= odd[i];
        sum -= even[i];
    }


    if(odd.size() > cnt)
        sum -= odd[cnt];
    else if(even.size() > cnt)
        sum -= even[cnt];

    cout << sum;
}