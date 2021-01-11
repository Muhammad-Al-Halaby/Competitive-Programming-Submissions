#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1
typedef long long ll;
#define endl '\n'
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    string s[4] = {"Carrots","Kiwis","Grapes","Waste"};
    pair<int,int> wasted[k];
    for(int i = 0;i<k;i++){
        int x,y;
        cin >> x >> y;
        wasted[i] = make_pair(x,y);
    }
    for(int i = 0;i<t;i++){
        int x,y;
        cin >> x >> y;
        int cnt = 0,w=0;
        for(int j = 0;j<k;j++){
            if(wasted[j].first < x || (wasted[j].first == x && wasted[j].second < y)){
                    cnt++;
            }
            else if(wasted[j].first == x && wasted[j].second == y){
                cout << s[3] << endl;
                w=1;
                break;
            }
        }
        int before = (x-1)*m + y - 1 - cnt;
        if(!w)
            cout << s[before%3] << endl;
    }
}
