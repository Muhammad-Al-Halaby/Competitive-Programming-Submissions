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

    int n;
    cin >> n;

    int a[1 << n];
    for(int i = 0;i < (1 << n);i++){
        cin >> a[i];
    }

    vector<int> v1, v2;

    for(int i = 0;i < (1 << n);i++)
        v1.push_back(i);

    while(v1.size() > 2) {
        for (int i = 0; i < v1.size(); i += 2) {
            if (a[v1[i]] > a[v1[i + 1]])
                v2.push_back(v1[i]);
            else
                v2.push_back(v1[i + 1]);
        }
        v1 = v2;
        v2.clear();
    }

    cout << (a[v1[0]] > a[v1[1]] ? v1[1] : v1[0]) + 1;

}