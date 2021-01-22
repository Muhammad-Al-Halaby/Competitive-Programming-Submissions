#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int query(int x, bool type){
    cout << (type ? "> " : "? ") << x << endl;
    int ret;   cin >> ret;
    if(ret == -1)   exit(0);
    return ret;
}

int ans(int x0, int d){
    cout << "! " << x0 << " " << d << endl;
    exit(0);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

    int n;  cin >> n;

    int mx = min(30, n), a[mx];
    set<int> s;
    for(int i = 0;i < mx;i++){
        int idx = 1;
        while(s.find(idx) != s.end()) idx = rnd() % n + 1;
        s.insert(idx);
        a[i] = query(idx, 0);
    }

    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(query(mid, 1))
            l = mid + 1;
        else
            r = mid - 1;
    }

    a[mx] = l;

    int g = 0;
    for(int i = 0;i <= mx;i++){
        for(int j = i + 1;j <= mx;j++){
            g = gcd(g, abs(a[i] - a[j]));
        }
    }

    int x0 = OO, d;
    for(ll i = 1;i * i <= g;i++){
        if(g % i == 0){
            int j = g / i;
            ll f1 = l - 1ll * i * (n - 1);
            ll f2 = l - 1ll * j * (n - 1);

            if(f1 >= 0 && f1 < x0){
                x0 = f1;
                d = i;
            }

            if(f2 >= 0 && f2 < x0){
                x0 = f2;
                d = j;
            }
        }
    }

    ans(x0, d);
}