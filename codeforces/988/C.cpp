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

    int t;
    cin >> t;

    map<int, vector<pii>> mp;
    for(int seq = 0; seq < t;seq++){
        int n, sum = 0;
        cin >> n;
        int arr[n];

        for(int i = 0;i < n;i++){
            cin >> arr[i];
            sum += arr[i];
        }
        map<int,int> check;
        for(int i = 0;i < n;i++){
            int c = check[sum - arr[i]];
            if(c != 0)continue;
            mp[sum - arr[i]].push_back(MP(seq + 1, i + 1));
            check[sum - arr[i]] = 1;
        }
    }

    for(auto p : mp){
        if(p.S.size() > 1){
            cout << "YES\n";
            cout << (p.S)[0].F << " " << (p.S)[0].S << '\n';
            cout << (p.S)[1].F << " " << (p.S)[1].S << '\n';
            return 0;
        }
    }

    cout << "NO";
}