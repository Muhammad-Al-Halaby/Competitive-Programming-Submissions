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


void go(int tc = 0){
    int n;  cin >> n;
    ll a[n];


    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    if(n == 1)  return cout << a[0], void();
    if(n == 2)  return cout << (a[0] | a[1]), void();

    ll ans = 0;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
            for(int k = j + 1;k < n;k++)
                ans = max(ans, a[i] | a[j] | a[k]);

    cout << ans << '\n';
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