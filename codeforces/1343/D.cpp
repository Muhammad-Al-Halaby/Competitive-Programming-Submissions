#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll in_range(ll a, ll l, ll r){
    return (a >= l && a <= r);
}
int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, k;  cin >> n >> k;
        int a[n];

        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        int freq[2 * k + 1] = {0}, prefix[2 * k + 2] = {0};
        for(int i = 0;i < n / 2;i++){
            prefix[min(a[i], a[n - i - 1]) + 1]++;
            prefix[max(a[i], a[n - i - 1]) + k + 1]--;
            freq[a[i] + a[n - i - 1]]++;
        }

        partial_sum(prefix, prefix + 2 * k + 2, prefix);

        int ans = OO;
        for(int i = 2;i <= 2 * k;i++){
            int cnt = prefix[i];
            ans = min(ans, cnt - freq[i] + 2 * ((n / 2) - cnt));
        }

        cout << ans << '\n';
    }
}