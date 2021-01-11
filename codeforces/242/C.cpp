#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int x0,y0,x1,y1,n;
set<pair<int,int> > allowed;
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {-1,1,0,0,1,-1,-1,1};
map<pair<int,int>,int> visited;

bool valid(int x, int y){
    return x >= 1 && x <= 1e9 && y >= 1 && y <= 1e9;
}

int traverse(int sx, int sy){
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    int depth = 1;
    int sz = 1;
    for(;!q.empty();++depth, sz =  q.size()){
        while(sz--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i < 8;i++){
                pair<int,int> p = make_pair(x+dx[i],y+dy[i]);
                if(x+dx[i] == x1 && y+dy[i] == y1){
                    return depth;
                }
                else if(allowed.find(p) != allowed.end() && valid(x+dx[i],y+dy[i])&& visited[p] != 1){
                    visited[p] = 1;
                    q.push(p);
                }
            }
        }
    }
    return -1;
}
int main(){
    init();
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    allowed.insert(make_pair(x0,y0));
    allowed.insert(make_pair(x1,y1));
    for(int i = 0;i<n;i++){
        int r,a,b;
        cin >> r >> a >> b;
        for(int i = a;i<=b;i++)
            allowed.insert(make_pair(r,i));
    }
    cout << traverse(x0,y0);
}