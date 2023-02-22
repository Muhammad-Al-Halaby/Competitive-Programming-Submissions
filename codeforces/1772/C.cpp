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
        int k, n;
        cin >> k >> n;
        int s = 1;

        auto check = [&](int diff) {
            int end = k - (diff-1) + ((diff * (diff + 1)) / 2 - 1);
            return end <= n;
        };

        int l = 1, r = k - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        int prev;
        for(int i = 0, step = 1;i < k;i++){
            if(k - i >= r) {
                cout << i + step << " ";
                prev = i + 1;
            }
            else {
                step++;
                cout << prev + step << " ";
                prev = prev + step;
            }
        }
        cout << '\n';
    }

}