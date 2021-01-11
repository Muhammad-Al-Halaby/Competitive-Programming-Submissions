#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1
typedef long long ll;
#define endl '\n'
#define EPS 1e-6
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int visited[(int)1e5+5];
int dp[(int)1e5+5];
vector< pair<int,int> > chars[200];
int main(){
    init();
    int n,m,x,q,ans=0;
    string s;
    cin >> n >> m >> x;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;
            cin >> c;
            chars[c].push_back(make_pair(i,j));
        }
    }

    cin >> q >> s;

    for(char c : s){
        if(chars[c].size() && c != 'S')continue;
        else if(chars[c + 32].size() && chars['S'].size()){
            if(!visited[c]){
                bool twohands = true;
                for(int i = 0;i<chars[c+32].size();i++){
                    for(int j = 0;j<chars['S'].size();j++){
                        double dist = hypot(chars[c+32][i].first - chars['S'][j].first,chars[c+32][i].second - chars['S'][j].second);
                        if(dist <= x)twohands = false;
                    }
                }
                visited[c]=1;
                if(twohands){
                    ans++;
                    dp[c]=1;
                }
                else{
                    dp[c]=0;
                }
            }
            else{
                ans+=dp[c];
            }
        }
        else{
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}