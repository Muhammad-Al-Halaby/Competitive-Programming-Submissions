#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();


    int t;  cin >> t;
    while(t--){
        int x;  string s;   cin >> x >> s;
        int n = s.size();
        for(int i = 0;s.size() < x;i++){
            int p = s[i] - '0' - 1;
            string d = s.substr(i + 1);
            while(s.size() < x && (p--))  s += d;
        }

        ll ans = n;
        for(int i = 0;i < x;i++){
            ll p = s[i] - '0';
            ans = (i + 1) + (ans - (i + 1)) * p;
            ans %= modulo;
            ans = (ans + modulo) % modulo;
        }
        cout << ans << '\n';
    }
}