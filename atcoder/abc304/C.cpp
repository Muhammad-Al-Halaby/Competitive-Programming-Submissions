#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    int n, d;
    cin >> n >> d;

    int x[n], y[n];
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }

    bool ans[n] = {};
    queue<int> infected;

    infected.push(0);
    ans[0] = 1;

    while(infected.size()){
        int j = infected.front();
        infected.pop();
        for(int i = 0;i < n;i++){
            if(ans[i])  continue;
            ll dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if(dist <= d * d){
                ans[i] = 1;
                infected.push(i);
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}
