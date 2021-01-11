#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
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

const int N = 1e5, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == '?'){
                for(char c = 'a';c <= 'c';c++){
                    if(i && i + 1 < n){
                        if(s[i-1] != c && s[i+1] != c){
                            s[i] = c;
                            break;
                        }
                    }
                    else if(i){
                        if(s[i-1] != c){
                            s[i] = c;
                            break;
                        }
                    }
                    else if(i + 1 < n){
                        if(s[i + 1] != c){
                            s[i] = c;
                            break;
                        }
                    }
                    else{
                        s[i] = c;
                        break;
                    }
                }
            }
        }

        bool ok = 1;
        for(int i = 0;i < n - 1;i++)
            if(s[i] == s[i + 1])    ok = 0;

        if(ok)
            cout << s;
        else
            cout << -1;

        cout << '\n';
    }


}