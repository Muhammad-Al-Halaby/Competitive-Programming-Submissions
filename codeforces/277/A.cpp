#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int n, m;
    cin >> n >> m;
    vector<int> lang[m+1];

    for(int i = 0;i<n;i++){
        int cnt;
        cin >> cnt;
        know[i+1] = bool(cnt);
        while(cnt--){
            int x;
            cin >> x;
            lang[x].push_back(i+1);
        }
    }

    for(int i = 1;i<=m;i++){
        for(int j = 0;j<lang[i].size();j++){
            for(int k = j+1;k<lang[i].size();k++){
                adj[ lang[i][j] ].push_back(lang[i][k]);
                adj[ lang[i][k] ].push_back(lang[i][j]);
            }
        }
    }

    int ans = 0, must = 0;
    for(int i = 1;i<= n;i++){
        if(!visited[i] && know[i])ans++,bfs(i);
        if(!know[i])must++;
    }

    cout << max(ans-1,0) + must;
}