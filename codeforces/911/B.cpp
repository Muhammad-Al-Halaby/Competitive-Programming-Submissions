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
    int n, a, b;    cin >> n >> a >> b;

    int ok = 0;
    for(int i = min(a, b);i >= 1;i--){
        for(int x = 1;x <= n;x++){
            int y = n - x;
            if(x * i <= a && y * i <= b){
                ok = i;
                break;
            }
        }
        if(ok)  break;
    }
    cout << ok;
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)  go(tc++);
}