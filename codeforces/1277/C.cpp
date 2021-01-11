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
        int n = s.size();
        string c1 = "twone", c2 = "one", c3 = "two";
        vector<int> ans;
        for(int i = 0;i < n;i++){
            //case 1
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for(int j = 0;i + j < n && j < 5;j++){
                if(c1[j] == s[i + j])   cnt1++;
            }

            if(cnt1 == 5){
                ans.PB(i + 3);
                i += 4;
                continue;
            }


            for(int j = 0;i + j < n && j < 3;j++){
                if(c2[j] == s[i + j])   cnt2++;
                if(c3[j] == s[i + j])   cnt3++;
            }

            if(cnt2 == 3 || cnt3 == 3){
                ans.PB(i + 2);
                i += 2;
                continue;
            }

        }

        cout << ans.size() << '\n';
        for(auto v : ans)
            cout << v << " ";
        cout << '\n';
    }
}