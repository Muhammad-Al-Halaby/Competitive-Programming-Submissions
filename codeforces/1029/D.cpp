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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int numofDigits(int n){
    if(n < 10)  return 1;
    int x = 0;
    while(n){
        x++;
        n /= 10;
    }
    return x;
}

int main()
{
    int n, k;   scanf("%d%d", &n, &k);

    int arr[n], cnt[n], mods[n];
    map<pair<int,int>, int> mp;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        
        mods[i] = arr[i] % k;
        cnt[i] = numofDigits(arr[i]);

        mp[{cnt[i], mods[i]}]++;
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){
        auto &it = mp[{cnt[i], mods[i]}];
        it--;
        int mod = arr[i];
        for(int j = 0;j < 11;j++){
            mod = (mod * 10ll) % k;
            if(mp.find({j + 1, ((mod == 0) ? 0 : k - mod)}) != mp.end())
                ans += mp[{j + 1, ((mod == 0) ? 0 : k - mod)}];
        }
        it++;
    }

    printf("%lld", ans);
}