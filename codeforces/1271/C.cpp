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

const int N = 2e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    init();

    ll n, sx, sy;  cin >> n >> sx >> sy;
    ll x[n], y[n];
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }

    ll ans = 0, ansx, ansy;
    for(int i = 0;i < 4;i++){
        ll nx = dx[i] + sx;
        ll ny = dy[i] + sy;

        if(nx < 0 || nx > 1e9 || ny < 0 || ny > 1e9)    continue;

        int cnt = 0;
        for(int k = 0;k < n;k++){
            ll mn = abs(x[k] - sx) + abs(y[k] - sy);
            ll d = abs(x[k] - nx) + abs(y[k] - ny) + 1;

            if(mn == d) cnt++;
        }

        if(cnt > ans){
            ans = cnt;
            ansx = nx;
            ansy = ny;
        }
    }

    cout << ans << '\n';
    cout << ansx << " " << ansy;
}