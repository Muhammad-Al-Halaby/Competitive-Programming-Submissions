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
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();

    int n;  cin >> n;
    int a[n], f[n], b[n], ans = 0;
    
    f[0] = 1;
    for(int i = 0;i < n;i++)    cin >> a[i];
    
    for(int i = 1;i < n;i++){
        if(a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
        else f[i] = 1;

        ans = max(ans, f[i]);
    }

    b[n - 1] = 1;
    for(int i = n - 2;i >= 0;i--){
        if(f[i] + 1 == f[i + 1]) b[i] = b[i + 1] + 1;
        else b[i] = 1;
    }

    for(int i = 1;i < n - 1;i++){
        if(a[i - 1] < a[i + 1])
            ans = max(ans, f[i - 1] + b[i + 1]);
    }

    cout << ans;
}





