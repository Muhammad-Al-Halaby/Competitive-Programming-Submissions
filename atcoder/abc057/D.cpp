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

const int N = 59, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, l, r;

ll a[N];

ll iterativeChoose(ll n, ll k){
    if(k > n)   return 0;
	ll ret = 1;
	for(ll i = k + 1;i <= n;i++){
		ll d = (i - k);
		ll q = i / d;
		ll r = i - q * d;
		ret = ret * q + ret * r / d;
	}
	return ret;
}

int main(){
    init();

    cin >> n >> l >> r;
    for(int i = 0;i < n;i++)    cin >> a[i];

    sort(a, a + n); reverse(a, a + n);

    long double sum = 0;

    int cnt1 = 0, cnt2 = 0;

    for(int i = 0;i < n;i++)    cnt1 += a[i] == a[l - 1];

    for(int i = 0;i < l;i++)    sum += a[i], cnt2 += a[i] == a[l - 1];;


    cout << fixed << setprecision(7) << 1.0 * sum / l << '\n';

    ll ans = 0;
    if(a[0] == a[l - 1]){
        for(int i = l;i <= r;i++)
            ans += iterativeChoose(cnt1, i);
        return cout << ans, 0;
    }
  
    cout << iterativeChoose(cnt1, cnt2);
}