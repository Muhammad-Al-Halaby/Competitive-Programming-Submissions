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
        string s;   cin >> s;
        string b = "desu", c = "masu";
        int n = s.size();
        if(s[n - 1] == 'o' && s[n - 2] == 'p'){
            cout << "FILIPINO\n";
            continue;
        }

        int cnt1 = 0, cnt2 = 0;
        for(int i = 0;i < 4;i++){
            if(b[i] == s[n - 4 + i])cnt1++;
            if(c[i] == s[n - 4 + i])cnt2++;
        }

        if(cnt1 == 4 || cnt2 == 4)
            cout << "JAPANESE\n";
        else
            cout << "KOREAN\n";
    }

}