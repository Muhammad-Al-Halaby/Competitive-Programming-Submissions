#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

ll llOO = 0x3f3f3f3f3f3f3f3f;



int main() {
//    freopen("zeros.in","r",stdin);
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        ll a[n], b[n], sorted[n];
        ll sum = 0;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++){
            sorted[i] = i;
            cin >> b[i];
            sum += b[i];
        }

        sort(sorted, sorted + n, [&](int x, int y){
           if(a[x] < a[y]) return true;
           if(a[x] == a[y]) return b[x] < b[y];
           return false;
        });

        ll mx = 0;
        for(int j = 0;j < n;j++){
            int i = sorted[j];
            if(a[i] >= mx && max(a[i], sum - b[i]) < sum){
                sum -= b[i];
                mx = a[i];
            }
        }
        cout << max(sum, mx) << '\n';
    }
}