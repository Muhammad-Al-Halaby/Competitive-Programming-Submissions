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

const int N = 1e6 + 10, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int ok = 1;
    for(int i = 0;i < n - 1;i++){
        if(abs(a[i] - a[i + 1]) > 1)
            ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}