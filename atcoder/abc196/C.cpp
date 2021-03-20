#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll n, mxsz;

int check(string a){
    if(a.empty() || a[0] == '0')   return 0;
    string s = a + a;
    ll x = stoll(s);
    return (x >= 1 && x <= n);
}

ll solve(string s){
    if(s.size() > mxsz) return 0;
    ll ret = check(s);
    for(char c = '0';c <= '9';c++)
        ret += solve(s + c);
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    cin >> n;

    string s = to_string(n);
    mxsz = s.size() / 2;

    cout << solve("");
}