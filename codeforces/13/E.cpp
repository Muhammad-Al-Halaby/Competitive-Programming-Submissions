#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N], root, cnt, jumps[N], nxt[N], out[N];

void updateBucket(int u){
    int fst = u / root * root;
    for(u = min(u, n - 1); u >= fst;u--){
        int v = u + a[u];
        if(v >= n){
            jumps[u] = 1;
            nxt[u] = n;
            out[u] = u;
        }
        else if(v < fst + root){
            jumps[u] = 1 + jumps[v];
            nxt[u] = nxt[v];
            out[u] = out[v];
        }
        else{
            jumps[u] = 1;
            nxt[u] = v;
            out[u] = u;
        }
    }
}

int u, v, b;

int main(){
    init();

    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> a[i];

    root = sqrt(n);
    cnt = (n + root - 1) / root;

    for(int i = cnt * root - 1;i >= 0;i -= root)  updateBucket(i);

    for(int i = 0;i < m;i++){
        int t;  cin >> t;
        if(t){
            cin >> u;   u--;

            int ans = 0;
            do{
                ans += jumps[u];
                v = out[u];
                u = nxt[u];
            }while(u < n);

            cout << v + 1 << " " << ans << '\n';

            continue;
        }

        cin >> u >> b;  u--;
        a[u] = b;
        updateBucket(u);
    }
}