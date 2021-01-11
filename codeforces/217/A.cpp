#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

vector<int> adj[105];
int visited[105];
int know[105];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0;i<adj[current].size();i++){
            if(not visited[adj[current][i]]){
                q.push(adj[current][i]);
                visited[adj[current][i]] = 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    pair<int, int> snowdrifts[n];

    for(int i = 1;i<=n;i++)
        cin >> snowdrifts[i].F >> snowdrifts[i].S;

    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(snowdrifts[i].F == snowdrifts[j].F || snowdrifts[i].S == snowdrifts[j].S){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for(int i = 1;i<= n;i++){
        if(!visited[i])ans++,bfs(i);
    }

    cout << max(ans-1,0);
}