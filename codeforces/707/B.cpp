#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cities[(int)1e5+5];

vector< pair<int,int> > roads[(int)1e5+5];

int main(){
    int n,m,k,ans=INT_MAX;
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++){
        int u,v,d;
        cin >> u >> v >> d;
        roads[u].push_back(make_pair(v,d));
        roads[v].push_back(make_pair(u,d));
    }
    if(k){

        for(int i = 0;i<k;i++){
            int x;
            cin >> x;
            cities[x] = 1;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<roads[i].size();j++){
                if(cities[roads[i][j].first] ^ cities[i]){
                    ans = min(ans,roads[i][j].second);
                }
            }
        }

    }
    if(!k || ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

}