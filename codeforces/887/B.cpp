#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
    init();

    int n;
    cin >> n;
    int c[n][6];
    set<int> s;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<6;j++){
            cin >> c[i][j];
            s.insert(c[i][j]);
        }


    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++)
            for(int c1 = 0;c1 < 6;c1++)
                for(int c2 = 0;c2 < 6;c2++)
                    s.insert(c[i][c1] + c[j][c2] * 10), s.insert(c[i][c1] * 10 + c[j][c2]);
    }

    int last = 0;
    for(auto x : s){
        if(x != last && x != last + 1)break;
        else last = x;
    }
    cout << last;
}