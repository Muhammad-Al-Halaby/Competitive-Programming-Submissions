#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll t[4 * N], lazy[4 * N];

int n;

void check(int v, int l, int r) {
    if (lazy[v]) {
        t[v] += (r - l + 1) * lazy[v];
        if (l != r) {
            lazy[v * 2 + 1] += lazy[v];
            lazy[v * 2 + 2] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void build(int v, int l = 0, int r = n - 1) {
    check(v, l, r);

    if (l == r)
        return t[v] = 0, void();

    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

void update(int v, int start, int end, ll val, int l = 0, int r = n - 1) {
    check(v, l, r);

    if (start <= l && end >= r) {
        t[v] += (r - l + 1) * val;
        if (l != r) {
            lazy[v * 2 + 1] += val;
            lazy[v * 2 + 2] += val;
        }
        return;
    }

    if (start > r || end < l) return;

    int mid = (l + r) / 2;
    update(2 * v + 1, start, end, val, l, mid);
    update(2 * v + 2, start, end, val, mid + 1, r);

    // sum
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

ll query(int v, int start, int end, int l = 0, int r = n - 1) {
    check(v, l, r);

    //  return proper value
    if (start > r || end < l) return 0;

    if (l >= start && r <= end)
        return t[v];

    int mid = (l + r) / 2;
    ll v1 = query(v * 2 + 1, start, end, l, mid);
    ll v2 = query(v * 2 + 2, start, end, mid + 1, r);

    // sum
    return v1 + v2;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> n >> q;

        build(0, 0, n - 1);

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < q; i++) {
            int x, idx, l, r;
            cin >> x;
            if (x == 1) {
                cin >> l >> r;
                l--, r--;
                update(0, l, r, 1);
            } else {
                cin >> idx;
                idx--;
                int cnt = query(0, idx, idx);
                int temp = a[idx];
                while (cnt--) {
                    int sum = 0;
                    while (temp) {
                        sum += temp % 10;
                        temp /= 10;
                    }
                    temp = sum;
                    if (temp < 10) break;
                }
                cout << temp << '\n';
            }
        }
    }
}