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

const int N = 1e4 + 9, M = 105, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int n, k;  cin >> n >> k;
    double a[n];
    double sum = 0;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        a[i] = x * (x + 1) / 2 * (1.0 / x);
        if(i < k)   sum += a[i];
    }

    double best = sum;
    for(int i = k;i < n;i++){
        sum -= a[i - k];
        sum += a[i];
        best = max(best, sum);
    }

    cout << fixed << setprecision(10) << best;
}


