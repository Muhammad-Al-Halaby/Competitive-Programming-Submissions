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

const int N = 1e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, q;
int grid[2][N];

int dx[] = {1,-1,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1};

bool valid(int i, int j){
    return i >= 0 && i < 2 && j >=0 && j < n;
}

int main(){
    init();

    cin >> n >> q;


    int blocked = 0;
    for(int i = 0;i < q;i++){
        int x, y;   cin >> x >> y;  x--, y--;
        grid[x][y] ^= 1;
        for(int k = 0;k < 6;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(!valid(nx, ny))  continue;

            if(grid[x][y]){
                if(grid[nx][ny]){
                    blocked++;
                }
            }
            else{
                if(grid[nx][ny]){
                    blocked--;
                }
            }
        }

        if(blocked == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}