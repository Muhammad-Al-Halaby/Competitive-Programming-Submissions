#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void rotate(int a[2][2]){
    swap(a[0][0], a[1][1]);
    swap(a[0][0], a[1][0]);
    swap(a[1][1], a[0][1]);
}

bool check(int a[2][2]){
    return a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int a[2][2];
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                cin >> a[i][j];
            }
        }

        int ok = 0;
        for(int i = 0;i < 4;i++){
            if(check(a))    ok = 1;
            rotate(a);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}