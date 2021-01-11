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

int main(){
    init();

    ll n, k;    cin >> n >> k;

    ll arr[n];
    map<int, vector<int>> mp;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll b2 = arr[i], b1 = arr[i] / k, b3 = arr[i] * k;
        if(b2 % k || b3 > 1e9 || b3 < -1e9)continue;
        if(!mp.count(b1) || !mp.count(b3))continue;
        vector<int> & v1 = mp[b1];
        vector<int> & v2 = mp[b3];
        ll a = lower_bound(v1.begin(), v1.end(), i) - v1.begin();
        ll b = v2.size() - (upper_bound(v2.begin(), v2.end(), i) - v2.begin());
        ans += a * b;
    }

    cout << ans;
}