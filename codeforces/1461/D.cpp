#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
ll llOO = 0x3f3f3f3f3f3f3f3f;

ll n, q, a[N];

ll prefix[N];

map<ll, int> mp;

void solve(int left = 0, int right = n - 1){
    if(left == right || a[left] == a[right]){
        mp[a[left] * (right - left + 1)] = 1;
        return;
    }

    ll sum = prefix[right] - (left ? prefix[left - 1] : 0);

    mp[sum] = 1;

    ll midSum = (a[left] + a[right]) / 2;
    int l = left, r = right;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid] > midSum)
            r = mid - 1;
        else
            l = mid + 1;
    }

    solve(left, r);
    solve(r + 1, right);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;  cin >> t;
    while(t--) {
        mp.clear();
        cin >> n >> q;
        for(int i = 0;i < n;i++)    cin >> a[i];
        sort(a, a + n);
        partial_sum(a, a + n, prefix);

        solve();
        for(int i = 0;i < q;i++){
            ll x;   cin >> x;
            if(mp.count(x))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}