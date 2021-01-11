#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge

#define F first
#define S second

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

}

const int N = 2e3 + 5;

int n, m, k;

vector<pair<int,int> > fire;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j){
  return i >=0 && i < n && j >= 0 && j < m;
}

int visited[N][N], ansX, ansY;

void bfs(){
  queue<pair<int, int> > q;
  for(int i = 0;i < k;i++){
    int x = fire[i].F, y = fire[i].S;
    q.push({x, y});
    visited[x][y] = 1;
  }
  
  int depth = 1, sz = q.size();
  for(;q.size();++depth, sz = q.size()){
    while(sz--){
      int x = q.front().F;
      int y = q.front().S;
      q.pop();
      
      for(int i = 0;i < 4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(valid(newX, newY) && !visited[newX][newY]){
          ansX = newX;
          ansY = newY;
          q.push({newX, newY});
          visited[newX][newY] = 1;
        }
      }
    }
  }
}


int main(){
	init();
  
  cin >> n >> m >> k;
	
  for(int i = 0;i < k;i++){
    int x, y;	cin >> x >> y;
    --x, --y;
    fire.push_back({x,y});
  }
  
  bfs();
  
  cout << ansX + 1 << " " << ansY + 1;
}