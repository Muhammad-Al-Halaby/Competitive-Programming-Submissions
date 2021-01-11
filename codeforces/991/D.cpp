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


int main(){
    init();

    string s[2]; cin >> s[0] >> s[1];
    int n = s[0].size(), ans = 0;
    for(int i = 1;i < n;i++){
        if(s[0][i] != 'X' && s[0][i - 1] != 'X' && s[1][i - 1] != 'X'){
            s[0][i] = 'X';
            ans++;
        }

        else if(s[1][i] != 'X' && s[0][i - 1] != 'X' && s[1][i - 1] != 'X'){
            s[1][i] = 'X';
            ans++;
        }

        if(s[0][i] != 'X' && s[1][i] != 'X' && (s[0][i - 1] != 'X' || s[1][i - 1] != 'X')){
            s[0][i] = 'X';
            s[1][i] = 'X';
            ans++;
        }
    }

    cout << ans;
}







