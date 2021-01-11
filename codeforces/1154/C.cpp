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

    ll a[3],arr[3];
    for(int i = 0;i < 3;i++){
        cin >> arr[i];
        a[i] = arr[i];
    }
    int fish[] = {0,-1,-1,0,0,-1,0};
    int ra[] =  {-1,0,0,-1,0,0,0};
    int ch[] =   {0,0,0,0,-1,0,-1};
    int three[] = {3,2,2};

    ll ans = 0;

    for(int day = 0;day < 7;day++){
        ll full_weeks = INT_MAX;
        for(int i = 0;i < 3;i++)
            full_weeks = min(full_weeks, a[i] / three[i]);

        for(int i = 0;i < 3;i++){
            a[i] -= full_weeks * three[i];
        }

        full_weeks *= 7;

        int dd = day;

        while(true){
            a[0] += fish[dd];
            a[1] += ra[dd];
            a[2] += ch[dd];
            if(a[0] < 0 || a[1] < 0 || a[2] < 0)break;
            dd++;
            if(dd == 7)dd = 0;
            full_weeks++;
        }

        for(int i = 0;i < 3;i++)
            a[i] = arr[i];

        ans = max(full_weeks, ans);
    }

    cout << ans;
}