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

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        string b;   cin >> b;
        string a(n, 0);
        int prev;
        for(int i = 0 ;i < n;i++){
            if(i == 0){
                a[i] = '1';
                prev = (a[i] - '0') + (b[i] - '0');
                continue;
            }

            if(b[i] == '1') {
                if(prev == 0)
                    a[i] = '1';
                if(prev == 1)
                    a[i] = '1';
                if(prev == 2)
                    a[i] = '0';
            }

            if(b[i] == '0') {
                if(prev == 0)
                    a[i] = '1';
                if(prev == 1)
                    a[i] = '0';
                if(prev == 2)
                    a[i] = '1';
            }

            prev = (a[i] - '0') + (b[i] - '0');
        }

        cout << a << '\n';
    }

}