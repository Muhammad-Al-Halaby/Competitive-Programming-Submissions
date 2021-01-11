#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 5e3 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int main(){
    init();

    int n, m;   cin >> n >> m;
    pii a[n], b[m];
    for(int i = 0;i < n;i++)    cin >> a[i].F >> a[i].S;
    for(int i = 0;i < m;i++)    cin >> b[i].F >> b[i].S;

    for(int i = 0;i < n;i++){
        int idx, x = a[i].F, y = a[i].S, dist = OO;
        for(int i = 0;i < m;i++){
            int d = abs(x - b[i].F) + abs(y - b[i].S);
            if(d < dist){
                dist = d;
                idx = i;
            }
        }
        cout << idx + 1 << '\n';
    }



}