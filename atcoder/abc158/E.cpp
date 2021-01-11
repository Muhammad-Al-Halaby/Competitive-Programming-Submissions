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

const int N = 3e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, p;   cin >> n >> p;
    string s;   cin >> s;

    reverse(s.begin(), s.end());

    ll ans = 0;
    if(p == 5){
        for(int i = 0;i < n;i++){
            if(s[i] == '0' || s[i] == '5')  ans += (n - i);
        }
    }

    if(p == 2){
        for(int i = 0;i < n;i++){
            if((s[i] - '0') % 2 == 0) ans += (n - i);
        }
    }

    if(p != 2 && p != 5){
        int mod[p] = {0};   mod[0]++;
        int x = 0;
        for(int i = 0, pw = 1;i < n;i++){
            x += (s[i] - '0') * pw;
            x %= p;
            pw *= 10;    pw %= p;
            ans += mod[x]++;
        }
    }

    cout << ans;
}