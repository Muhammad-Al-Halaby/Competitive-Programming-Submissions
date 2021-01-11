#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc){



    ll n, m, k;    cin >> n >> m >> k;
    ll a[n + 1] = {0}, b[m + 1] = {0};
    for(int i = 1;i <= n;i++)    cin >> a[i];
    for(int i = 1;i <= m;i++)    cin >> b[i];

    partial_sum(a, a + n + 1, a);
    partial_sum(b, b + m + 1, b);

    int ans = 0;
    for(int i = 0;i <= n;i++){
        ll left = k - a[i];
        if(left < 0)    continue;

        int l = 0, r = m;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(b[mid] <= left)
                l = mid + 1;
            else
                r = mid - 1;
        }

        ans = max(ans, i + r);
    }

    cout << ans;
}




int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;//  cin >> t;
    while(t--)  go(tc++);

}