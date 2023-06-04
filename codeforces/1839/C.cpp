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

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (a[n - 1] == 1) {
            cout << "NO\n";
            continue;
        }

        vector<vector<int>> ans;
        int ones = 0;
        for(int i = 0;i < n;i++){
            if(a[i] == 0){
                vector<int> subarray;
                for(int j = 0;j < ones;j++)
                    subarray.push_back(0);
                subarray.push_back(ones);
                ones = 0;
                ans.push_back(subarray);
            }
            else{
                ones++;
            }
        }

        cout << "YES\n";
        for(int i = ans.size() - 1;i >= 0;i--) {
            for (auto x: ans[i])
                cout << x << " ";
        }
        cout << '\n';
    }
}