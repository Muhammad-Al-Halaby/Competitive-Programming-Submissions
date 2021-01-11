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

int divisors[(int) 1e6 + 5];

int main(){
    init();

    int t;  cin >> t;
    while(t--){

        for(int i = 0;i < 1e6 +5;i++)
            divisors[i] = 0;

        int n;  cin >> n;

        ll arr[n]; loop(i,0,n) cin >> arr[i];

        sort(arr, arr + n);
        loop(i,0,n)
            divisors[arr[i]]++;

        //first check
        ll x = arr[0] * arr[n - 1];
        int check = 1;
        for(int i = 0;i <= n / 2;i++){
            if(arr[i] * arr[n - i - 1] != x){
                check = 0;
                break;
            }
        }
        //second check
        if(check){
            for(int i = 0;i < n;i++){
                //divisors of each divisor
                for(ll j = 2;j * j <= arr[i];j++){
                    if(arr[i] % j == 0){
                        int ok = 1;
                        ok &= divisors[j];
                        ok &= divisors[arr[i] / j];
                        if(!ok){
                            check = 0;
                            break;
                        }
                    }
                }

                if(!check)
                    break;
            }
        }
        if(check)
            cout << x << '\n';
        else
            cout << -1 << '\n';

    }
}