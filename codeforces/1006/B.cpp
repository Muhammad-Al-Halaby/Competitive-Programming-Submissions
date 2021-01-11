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
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<pair<int,int>> v;

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        v.push_back(MP(x,i));
    }

    sort(v.begin(),v.end());
    vector<int> ans;
    ans.push_back(0);
    int sum = 0;
    for(int i = n - k;i < n;i++){
        ans.PB(v[i].S + 1);
        sum += v[i].F;
    }
    sort(ans.begin(),ans.end());
    ans[ans.size() - 1] = n;
    cout << sum << '\n';
    for(int i = 1;i < ans.size();i++){
        cout << ans[i] - ans[i - 1] << " ";
    }
}