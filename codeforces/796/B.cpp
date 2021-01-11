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

int holes[(int)1e6+5];
int dp[(int)1e5+5];
int main(){
    init();
    int n,m,k,pos=1,fall;
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        holes[x]=1;
    }
    fall=holes[pos];
    for(int i =0;i<k;i++){
        int x,y;
        cin >> x >> y;
        if(fall == 0){
            if(x == pos)pos=y;
            else if(y == pos)pos=x;
            fall=holes[pos];
        }
    }
    cout << pos;
}
