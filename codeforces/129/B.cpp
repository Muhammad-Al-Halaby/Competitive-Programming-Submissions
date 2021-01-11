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

int freq[(int)1e6+5];
//int dp[(int)1e6+5];
int main(){
    init();
    int n,m,ans=0;
    cin >> n >> m;
    pair<int,int> arr[m];
    for(int i = 0;i<m;i++){
        cin >> arr[i].first >> arr[i].second;
        freq[arr[i].first]++;
        freq[arr[i].second]++;
    }
    int siz = 1;
    while(siz){
        set< pair<int,int> > s;
        for(int i = 0;i<m;i++){
            if(freq[arr[i].first] == 1)
                s.insert(arr[i]);
            if(freq[arr[i].second] == 1)
                s.insert(arr[i]);
        }
        for(auto p : s){
            freq[p.first]--;
            freq[p.second]--;
        }
        if(s.size())ans++;
        siz = s.size();
    }
    cout << ans;
}