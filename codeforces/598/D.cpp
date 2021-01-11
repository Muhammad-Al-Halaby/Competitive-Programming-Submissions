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
int visited[1005][1005];
int ans[100005];

int n, m, k, currAns, currAnsIdx;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


bool valid(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m;
}

int traverse(int x, int y){
    int res = 0;
    visited[x][y] = currAnsIdx;
    for(int i = 0;i < 4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(valid(newX,newY) && !visited[newX][newY]){

            if(grid[newX][newY] == '*')
                res++;
            else{
                res += traverse(newX,newY);
            }
        }
    }
    return res;
}

int main(){
    init();

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> grid[i][j];

    for(int i = 0;i < k;i++){
        int x, y;
        cin >> x >> y;
        --x, --y;
        currAnsIdx = i + 1;
        if(!visited[x][y]){
            int res = traverse(x,y);
            ans[currAnsIdx] = res;
        }
        cout << ans[visited[x][y]] << '\n';
    }
}
