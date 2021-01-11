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

const int N = 2005, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

ll fac(ll n){
    ll ans = 1;
    for(ll i = n;i > 1;i--) ans *= i;
    return ans;
}
int main(){
    init();

    string s;   cin >> s;
    set<string> st;
    set<char> check(s.begin(), s.end());
    int n = s.size();
    for(int i = 1;i < (1 << n);i++){
        string p = "";
        for(int j = 0;j < s.size();j++){
            if((i >> j) & 1)    p += s[j];
        }
        sort(p.begin(), p.end());
        set<char> dis(p.begin(), p.end());
        if(dis.size() != check.size())  continue;
        st.insert(p);
    }

    ll ans = 0;
    for(auto p : st){
        int fr[10] = {};
        for(int i = 0;i < p.size();i++) fr[p[i] - '0']++;
        ll total = fac(p.size());
        for(int i = 0;i < 10;i++)   total /= fac(fr[i]);

        if(fr[0]){
            fr[0]--;
            ll zs = fac(p.size() - 1);
            for(int i = 0;i < 10;i++)   zs /= fac(fr[i]);
            total -= zs;
        }
        ans += total;
    }
    cout << ans;
}







