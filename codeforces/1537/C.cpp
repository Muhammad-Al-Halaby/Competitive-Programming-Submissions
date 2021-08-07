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
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        sort(a, a + n);

        int mn = OO;
        for(int i = 1;i < n;i++){
            mn = min(mn, a[i] - a[i - 1]);
        }

        for(int i = 1;i < n;i++) {
            if (a[i] - a[i - 1] == mn) {
                cout << a[i - 1] << " ";
                for(int j = i + 1;j < n;j++)
                    cout << a[j] << " ";
                for(int j = 0;j < i - 1;j++)
                    cout << a[j] << " ";
                cout << a[i] << " ";
                break;
            }
        }
        cout << '\n';
    }

}