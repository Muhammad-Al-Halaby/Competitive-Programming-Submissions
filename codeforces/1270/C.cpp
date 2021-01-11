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

void init()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 10, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main()
{
    init();

    int t;
    cin >> t;
    while(t--){
        int n;  cin >> n;
        ll sum = 0, x = 0;
        for(int i = 0; i < n; i++){
            int a;  cin >> a;
            sum += a;
            x ^= a;
        }

        ll a = ((1ll) << 50) - 1;
        a &= ~x;
        a &= ~1;
        if(sum & 1){
            a |= 1;
        }

        ll d = 2 * (x ^ a) - (sum + a);

        cout << 3 << '\n' << a << " " << d / 2 << " " << d / 2 << '\n';

    }

}







