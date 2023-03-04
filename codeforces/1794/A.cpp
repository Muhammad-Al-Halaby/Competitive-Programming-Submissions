#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

bool isP(string s){
    int n = s.size();
    for(int i = 0;i < n / 2;i++){
        if(s[i] != s[n - i - 1])    return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s = "";
        int ans = 0;
        for(int i = 0;i < n * 2 - 2;i++){
            string x;
            cin >> x;

            if(x.size() == n - 1){
                if(s == ""){
                    s = x;
                }
                else{
                    string t = s;
                    t.pop_back();
                    if(x.substr(1) == t){
                        x += s.back();
                        ans = isP(x);
                    }
                    else{
                        s += x.back();
                        ans = isP(s);
                    }
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}