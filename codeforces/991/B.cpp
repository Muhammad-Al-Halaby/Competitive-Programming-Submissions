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

const int N = 2005, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int n;  cin >> n;
    int a[n];   for(int i = 0;i < n;i++)    cin >> a[i];
    sort(a, a + n);
    int sum = accumulate(a, a + n, 0);
    int left = ceil(4.5 * n - sum);


    int ans = 0;
    for(int i = 0;i < n;i++){
        if(left <= 0)   break;
        left -= 5 - a[i];
        ans++;
    }

    cout << ans;

}







