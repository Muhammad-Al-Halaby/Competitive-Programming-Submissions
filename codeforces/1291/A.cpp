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
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        string s;   cin >> s;

        while(!s.empty() && (s[n-1] - '0') % 2 == 0){
            s.pop_back();
            n--;
        }

        if(s.empty()){
            cout << -1 << '\n';
            continue;
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += (s[i] - '0');
        }

        if(sum % 2 == 0){
            cout << s << '\n';
            continue;
        }

        int del = 0;
        for(int i = 0;i < n;i++){
            if((s[i] - '0') % 2){
                del = i;
                break;
            }
        }
        if(n == 1 || del == n - 1){
            cout << -1 << '\n';
            continue;
        }



        vector<int> ans;

        for(int i = n-1;~i;i--)
            if(i != del)    ans.push_back(s[i] - '0');
        while(ans.back() == 0)  ans.pop_back();

        if(ans.empty()){
            cout << -1 << '\n';
            continue;
        }
        for(int i = ans.size() - 1;~i;i--) cout << ans[i];


        cout << '\n';
    }
}









