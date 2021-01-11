#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc){
    int n, m;   cin >> n >> m;

    for(int i = 0;i < m;i++){
        int k;  cin >> k;
        int pos[n + 1] = {0}, neg[n + 1] = {0}, ok = 1;
        for(int j = 0;j < k;j++){
            int x;  cin >> x;
            pos[abs(x)] += x > 0;
            neg[abs(x)] += x < 0;
            if(pos[abs(x)] && neg[abs(x)])  ok = 0;
        }
        if(ok)   return cout << "YES", void();
    }
    cout << "NO";

}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)  go(tc++);
}