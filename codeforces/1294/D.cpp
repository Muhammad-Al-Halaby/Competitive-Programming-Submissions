#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 4e5+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int mods[N], current[N];

int main(){
    init();

    int q, x;   cin >> q >> x;
    iota(mods, mods + x, 0);
    int mex = 0;
    for(int i = 0;i < q;i++){
        int a;  cin >> a;
        if(mods[a%x] <= q){
            current[mods[a%x]] = 1;
            mods[a % x]+= x;
        }
        while(current[mex]) mex++;
        cout << mex << '\n';
    }
}