#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 109, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, q, mx, dp[N][N][M];

ll query(int x1, int y1, int x2, int y2, int t){
    ll sum = 0;
    for(int c = 0;c <= 10;c++){
        ll cnt = dp[x2][y2][c] - dp[x1 - 1][y2][c] - dp[x2][y1 - 1][c] + dp[x1 - 1][y1 - 1][c];
        sum += ((c + t) % (mx + 1)) * cnt;
    }
    return sum;
}


int main(){
    init();

    cin >> n >> q >> mx;
    for(int i = 0;i < n;i++){
        int x, y, c;    cin >> x >> y >> c;
        dp[x][y][c]++;
    }


    for(int k = 0;k <= mx;k++)
        for(int i = 1;i < N;i++)
            for(int j = 1;j < N;j++)
                dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];


    for(int i = 0;i < q;i++){
        int x1, y1, x2, y2, t;  cin >> t >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2, t) << '\n';
    }
}