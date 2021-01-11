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

const int N = 505, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        string s;   cin >> s;
        int ans = 0;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == 'A') continue;
            for(int j = i - 1;j >= 0;j--){
                if(s[j] == 'P') continue;
                ans = max(ans, i - j);
                break;
            }
        }

        cout << ans << '\n';
    }

}





