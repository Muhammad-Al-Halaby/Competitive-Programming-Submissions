#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int moves[300];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j){
    return i >= -1e9 && i <= 1e9 && j >= -1e9 && j <= 1e9;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    moves['R'] = 0;
    moves['L'] = 1;
    moves['U'] = 2;
    moves['D'] = 3;

    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;

        int n = s.size();

        auto check = [&](int bx, int by) {
            int nxtX = 0, nxtY = 0;
            for (int i = 0; i < n; i++) {
                int x = nxtX + dx[moves[s[i]]];
                int y = nxtY + dy[moves[s[i]]];
                if(x == bx && y == by)  continue;
                nxtX = x;
                nxtY = y;
            }
            return (nxtX == 0 && nxtY == 0);
        };

        int nxtX = 0, nxtY = 0, ok = 1;
        for(int i = 0;i < n;i++){
            nxtX += dx[moves[s[i]]];
            nxtY += dy[moves[s[i]]];
            if(check(nxtX, nxtY) && valid(nxtX, nxtY)){
                cout << nxtX << " " << nxtY << '\n';
                ok = 0;
                break;
            }
        }

        if(ok)
            cout << 0 << " " << 0 << '\n';
    }
}