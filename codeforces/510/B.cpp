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
int n, m, startX, startY;
char grid[55][55];
int visited[55][55];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool valid(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m;
}

void dfs(int x, int y, int depth){
    visited[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(valid(newX,newY) && grid[newX][newY] == grid[x][y]){
            if(newX == startX && newY == startY && depth >= 3){
                cout << "Yes";
                exit(0);
            }
            else if(!visited[newX][newY]){
                dfs(newX,newY,depth+1);
            }
        }
    }
}
int main(){
    init();
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            memset(visited, 0, sizeof visited);
            startX = i;
            startY = j;
            dfs(i,j,0);
        }
    }
    cout << "No";
}