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

int fr[(int) 2e5 + 10];

int main(){
    init();
    int n, mx = 0;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        fr[arr[i]]++;
        if(fr[arr[i]] > 2)
            return cout << "NO", 0;
        mx = max(mx, arr[i]);
    }

    vector<int> a,b;
    for(int i = 0;i <= mx;i++){
        if(fr[i] > 1){
            a.push_back(i);
            b.push_back(i);
        }
        else if(fr[i]) a.push_back(i);
    }
    cout << "YES\n" << a.size() << '\n';
    for(int i = 0;i < a.size();i++){
        cout << a[i];
        if(i < n - 1)
            cout << " ";
    }
    cout << '\n' << b.size() << '\n';
    for(int i = b.size() - 1;i >= 0;i--){
        cout << b[i];
        if(i < n - 1)
            cout << " ";
    }
}