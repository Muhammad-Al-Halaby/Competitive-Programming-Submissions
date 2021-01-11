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


bool cmp(pair<pair<int, int>, ll> a, pair<pair<int, int>, ll> b){
    return a.F.S > b.F.S || a.F.F < b.F.F;
}

int main(){
    init();
    int n;
    cin >> n;
    pair<pair<int, int>, ll> arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i].S;
        ll x = arr[i].S;
        int cnt = 0;
        while(x % 2 == 0){
            cnt++;
            x /= 2;
        }
        arr[i].F.F = cnt;
        cnt = 0;
        while(x % 3 == 0){
            cnt++;
            x /= 3;
        }
        arr[i].F.S = cnt;
    }

    sort(arr, arr + n, cmp);

    for(int i = 0;i < n;i++){
        cout << arr[i].S << " ";
    }
}