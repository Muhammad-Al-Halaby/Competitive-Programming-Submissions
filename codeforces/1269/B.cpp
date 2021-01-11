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
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2005, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
//    init();

    int n, m;   scanf("%d%d", &n,&m);

    vector<int> a, b;
    unordered_map<int, int> freqA, freqB;

    for(int i = 0;i < n;i++){
        int x;  scanf("%d", &x);
        if(freqA[x] == 0)   a.push_back(x);
        freqA[x]++;

    }

    for(int i = 0;i < n;i++){
        int x;  scanf("%d", &x);
        if(freqB[x] == 0)   b.push_back(x);
        freqB[x]++;
    }


    unordered_map<int, int> xs;


    for(auto x : a){
        for(auto y : b){
            int modVal = (y >= x) ? y - x : m - x + y;
            int cntX = freqA[x], cntY = freqB[y];
            if(cntX != cntY)    continue;
            xs[modVal] += cntX;
        }
    }

    int ans = 1e9 + 10;
    for(auto p : xs){
//        cout << p.F << " " << p.S << '\n';
        if(p.S == n)
            ans = min(ans, p.F);
    }

    printf("%d", ans);
}







