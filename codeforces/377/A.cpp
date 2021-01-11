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
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char grid[505][505];
bool visited[505][505];
int n, m, k;


bool valid(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m;
}

void dfs(int i, int j){
    visited[i][j] = 1;
    int children = 0;
    for(int nxt = 0;nxt  < 4;nxt++){
        int x = i + dx[nxt], y = j + dy[nxt];
        if(valid(x,y) && !visited[x][y] && grid[x][y] == '.'){
            children++;
            dfs(x,y);
            if(grid[x][y] == 'X')children--;
        }
    }
    if(children == 0 && k){
        grid[i][j] = 'X';
        k--;
    }
}

int main(){
    init();
    cin >> n >> m >> k;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> grid[i][j];

    int d = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(d && grid[i][j] == '.'){
                dfs(i, j);
                d = 0;
            }
            cout << grid[i][j];
        }
        cout << '\n';
    }
}