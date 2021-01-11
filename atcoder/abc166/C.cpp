#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int ok[N];

int main(){
    init();

    int n, m;   cin >> n >> m;
    int a[n + 1];
    for(int i = 1;i <= n;i++)    cin >> a[i], ok[i] = 1;


    for(int i = 0;i < m;i++){
        int u, v;   cin >> u >> v;
        if(a[u] <= a[v])   ok[u] = 0;
        if(a[v] <= a[u])   ok[v] = 0;
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans += ok[i];
    }
    cout << ans;
}