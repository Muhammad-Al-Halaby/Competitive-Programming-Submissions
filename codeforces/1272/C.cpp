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

const int N = 5e3 + 5, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int freq[300];

int main(){
    init();

    int n, k;   cin >> n >> k;
    string s;   cin >> s;

    for(int i = 0;i < k;i++){
        char c; cin >> c;
        freq[c] = 1;
    }

    ll ans = 0, len = 0;
    for(int i = 0;i <= n;i++){
        char c = (i < n) ? s[i] : '0';
        if(freq[c] == 0){
            ans += (len * (len + 1) / 2);
            len = 0;
            continue;
        }

        len++;
    }

    cout << ans;
}