#include<bits/stdc++.h>
using namespace std;

int ans=1;
int levels[2001];
vector<int> adj[2001];
bool visited[2001];
void bfs(int s){
    queue<int> q;
    q.push(s);
    levels[s] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        visited[v] = true;
        for(int i = 0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]){
                q.push(adj[v][i]);
                levels[adj[v][i]]= levels[v]+1;
                ans=max(ans,levels[adj[v][i]]);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> candidates;
    vector<int> roots;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        if(x != -1)
            adj[x].push_back(i);
        else
            candidates.push_back(i);
    }
    for(int i = 0;i<candidates.size();i++){
        if(!adj[candidates[i]].empty()){
            roots.push_back(candidates[i]);
        }
    }
    for(int i = 0;i<roots.size();i++){
        int root = roots[i];
        if(!visited[root])
            bfs(root);
    }
    cout << ans;
}