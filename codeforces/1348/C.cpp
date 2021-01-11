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
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, k;  cin >> n >> k;

        string s;   cin >> s;
        sort(s.begin(), s.end());
        if(s[k - 1] != s[0]){
            cout << s[k - 1] << '\n';
            continue;
        }

        string ans = "";    ans += s[0];
        if(n == k){
            cout << ans << '\n';
            continue;
        }

        if(s[k] != s[n - 1]){
            ans += s.substr(k);
            cout << ans << '\n';
            continue;
        }

        int rem = ceil(1.0 * (n - k) / k);
        while(rem--)    ans += s[n - 1];

        cout << ans << '\n';
    }
}