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

    int n, m, h, k;
    cin >> n >> m >> h >> k;

    string s;
    cin >> s;

    set<pair<int, int>> items;
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        items.insert({x, y});
    }


    int i, posx = 0, posy = 0;
    for(i = 0;i < n;i++){
        if(s[i] == 'U'){
            posy++;
        }
        else if(s[i] == 'D'){
            posy--;
        }
        else if(s[i] == 'R'){
            posx++;
        }
        else if(s[i] == 'L'){
            posx--;
        }
        h--;
        if(h < 0) break;
        if(h < k && items.find({posx, posy}) != items.end()){
            items.erase({posx, posy});
            h = k;
        }
    }

    cout << (i == n ? "Yes" : "No");
}