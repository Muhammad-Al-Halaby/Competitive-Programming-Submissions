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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(v.size()){
                if(x != v.back())
                    v.push_back(x);
            }
            else v.push_back(x);
        }

        n = v.size();

        if(n == 1){
            cout << "YES\n";
            continue;
        }

        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(i == 0 && v[i + 1] > v[i])
                cnt++;
            if(i == n - 1 && v[i] < v[i - 1])
                cnt++;
            if(i > 0 && i + 1 < n && v[i] < v[i - 1] && v[i] < v[i + 1])
                cnt++;
        }

        cout << (cnt == 1 ? "YES" : "NO") << '\n';
    }
}