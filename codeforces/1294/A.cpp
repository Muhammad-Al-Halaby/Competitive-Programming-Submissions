#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e5+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();


    int t;  cin >> t;
    while(t--){
        int a[3];
        int n; cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a + 3);
        int diff = (a[2] - a[0]) + (a[2] - a[1]);
        n -= diff;

        if(n >= 0 && n % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }




}