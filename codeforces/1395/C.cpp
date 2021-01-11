#include "bits/stdc++.h"

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

const int N = 209, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int n, m, mask = (1 << 10) - 1;
int a[N], b[N];


int compareBits(int x, int y){
    for(int i = 0;i < 10;i++)
        if(!((1 << i) & x) && ((1 << i) & y))
            return 0;
    return 1;
}

bool ok(){
    for(int i = 0;i < n;i++){
        bool atleastone = 0;
        for(int j = 0;j < m;j++){
            int x = a[i] & b[j];
            if(compareBits(mask, x)){
                atleastone |= 1;
            }
        }
        if(atleastone == 0) return 0;
    }
    return 1;
}

void go(int tc = 0){
    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int i = 0;i < m;i++)    cin >> b[i];

    for(int i = 9;i >= 0;i--){
        mask ^= (1 << i);
        if(!ok())
            mask ^= (1 << i);
    }

    cout << mask;

}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}