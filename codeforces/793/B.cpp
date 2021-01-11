#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
char grid[1005][1005];
int visited[1005][1005][2][5];

int n, m;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


bool valid(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m;
}

ll traverse(int x, int y, int d, int t){
    if(grid[x][y] == 'T')return t;
    visited[x][y][d][t] = 1;
    ll res = INT_MAX;
    for(int i = 0;i < 4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(valid(newX,newY) && !visited[newX][newY][d][t]){
            if(grid[newX][newY] != '*'){
                ll turns = 0;
                if(d == 0 && dy[i] == 0)
                    turns++;
                if(d == 1 && dx[i] == 0)
                    turns++;
                if(t + turns > 2)continue;
                res = min(res,traverse(newX,newY,((turns)?!d:d),turns + t));
            }
        }
    }
    return res;
}


int main(){
    init();

    cin >> n >> m;
    int x, y;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                x = i;
                y = j;
            }
        }
    }

    int ans1 = traverse(x,y,0,0);
    int ans2 = traverse(x,y,1,0);

    cout << ((ans1 <= 2 || ans2 <= 2)?"YES":"NO");
}
