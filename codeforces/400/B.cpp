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

int main(){
    init();
    int n,m;
    bool possible = 1;
    set<int> s;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int d,c;
        for(int j = 0;j<m;j++){
            char x;
            cin >> x;
            if(x == 'G') d=j;
            else if(x == 'S')c=j;
        }
        if(d > c)possible = 0;
        else s.insert(c-d);
    }
    if(possible)
        cout << s.size();
    else
        cout << -1;
}