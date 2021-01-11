#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
}

const int N = 150 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int idx[N][2];

int main(){
    init();

    int n, m, mx = 0;   cin >> n >> m;
    for(int i = 0;i < n;i++){
        bool w = 1;
        idx[i][0] = idx[i][1] = -1;
        for(int j = 0;j < m;j++){
            char c; cin >> c;
            if(c == 'W' && w)    idx[i][0] = j, w = 0;
            if(c == 'W')    idx[i][1] = j, mx = i;
        }
    }

    int ans = 0, curr = 0;
    for(int i = 0;i < n;i++){
        int nxt = idx[i][!(i & 1)];

        if(nxt == -1)   nxt = curr;
        if(i + 1 < n){

            if(idx[i + 1][!(i & 1)] == -1)  idx[i + 1][!(i & 1)] = curr;

            if(i & 1)
                nxt = min(nxt, idx[i + 1][!(i & 1)]);
            else
                nxt = max(nxt, idx[i + 1][!(i & 1)]);
        }

        ans += abs(curr - nxt);
        curr = nxt;
    }

    cout << ans + mx;
}