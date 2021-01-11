#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

vector<int> pos[(int)1e5+1];

int main(){
    init();
    int n;
    cin >> n;
    set<int> s;
    vector< pair<int,int> > ans;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        pos[x].push_back(i);
        s.insert(x);
    }
    for(auto x : s){
        int include=1,diff = -1;
        for(int i = 1;i<pos[x].size();i++){
            if(diff == -1)diff = pos[x][i] - pos[x][i-1];
            else if(diff != pos[x][i] - pos[x][i-1])include = 0;
        }
        if(diff == -1)diff = 0;
        if(include)ans.push_back(make_pair(x,diff));
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';

    for(auto p : ans){
        cout << p.first << " " << p.second << '\n';
    }

}