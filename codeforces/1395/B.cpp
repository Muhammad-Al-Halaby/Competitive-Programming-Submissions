#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 209, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int n, m, vis[N][N];


void solve(){
    int cnt = n * m - 3;
    int x, y;
    x = y = 1;
    while(cnt){
        while(x <= n){
            if(vis[x][y]){
                if(x == n)  break;
                x++;
                continue;
            }
            cout << x << " " << y << '\n';
            cnt--;
            vis[x][y] = 1;
        }

        if(cnt == 0)    break;

        y++;
        while(x >= 1){
            if(vis[x][y]){
                if(x == 1)  break;
                x--;
                continue;
            }
            cout << x << " " << y << '\n';
            cnt--;
            vis[x][y] = 1;
        }

        y++;
    }
}
void go(int tc = 0){
    int x, y; cin >> n >> m >> x >> y;
    vis[x][y] = 1;
    vis[x][1] = 1;
    vis[1][1] = 1;



    cout << x << " " << y << '\n';
    cout << x << " " << 1 << '\n';
    cout << 1 << " " << 1 << '\n';

    x = y = 1;

    solve();
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}