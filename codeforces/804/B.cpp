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

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string s;   cin >> s;

    ll bs = 0, ans = 0;
    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == 'a'){
            ans = (ans + bs) % modulo;
            bs = (bs * 2) % modulo;
        }
        else{
            bs = (bs + 1) % modulo;
        }
    }

    cout << ans;
}