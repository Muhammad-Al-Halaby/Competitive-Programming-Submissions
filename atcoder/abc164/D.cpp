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

int mod[2019];

int main(){
    init();

    string s;   cin >> s;
    reverse(s.begin(), s.end());

    int n = s.size();

    ll x = 0, ans = 0;

    mod[0]++;
    for(ll i = 0, p = 1;i < n;i++){
        x = p * (s[i] - '0') + x;

        x %= 2019;

        ans += mod[x]++;

        p = (p * 10) % 2019;
    }

    cout << ans;
}