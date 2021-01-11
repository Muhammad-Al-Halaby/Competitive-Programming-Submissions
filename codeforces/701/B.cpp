#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m,rs=0,cls=0;
    cin >> n >> m;
    ll cells = (ll) n * n;
    int rows[(int)1e5+5]={0};
    int columns[(int)1e5+5]={0};
    for(int i = 0 ;i< m;i++){
        int x,y;
        cin >> x >> y;
        if(!rows[x]){
            cells-=n;
            rows[x] = 1;
            rs++;
            cells+=cls;
        }
        if(!columns[y]){
            cells-=n;
            columns[y] = 1;
            cls++;
            cells+=rs;
        }
        cout << cells << " ";
    }
}