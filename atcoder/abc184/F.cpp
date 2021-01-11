#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, t;
int a[N];

void build(int i, int end, ll sofar, vector<ll> &v){
    if(i == end)
        return v.push_back(sofar), void();

    build(i + 1, end, sofar + a[i], v);
    build(i + 1, end, sofar, v);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    cin >> n >> t;

    for(int i = 0;i < n;i++)
        cin >> a[i];

    int mid = n / 2;
    vector<ll> v1, v2;
    build(0, mid, 0, v1);
    build(mid, n, 0, v2);

    sort(v2.begin(), v2.end());

    ll ans = 0;
    for(int i = 0;i < v1.size();i++){
        ll x = v1[i];
        int l = 0, r = v2.size() - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(v2[mid] > t - x)
                r = mid - 1;
            else
                l = mid + 1;
        }

        if(r >= 0 && r < v2.size())
            ans = max(ans, x + v2[r]);
    }

    cout << ans;
}