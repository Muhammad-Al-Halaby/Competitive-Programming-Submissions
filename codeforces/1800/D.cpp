#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string a;
        cin >> a;

        int ans = 0;
        for(int i = 0;i < n - 1;i++){
            int distinct = 1;
            if(i - 2 >= 0 && i + 1 < n){
                if(a[i] == a[i - 2] && a[i + 1] == a[i - 1])    distinct = 0;

            }
            if(i - 1 >= 0 && i + 1 < n){
                if(a[i] == a[i - 1] && a[i] == a[i + 1])    distinct = 0;
            }
            if(i + 2 < n && i - 1 >= 0){
                if(a[i] == a[i + 2] && a[i + 1] == a[i - 1])    distinct = 0;
            }
            if(i - 1 >= 0 && i + 1 < n){
                if(a[i - 1] == a[i + 1])    distinct = 0;
            }
            ans += distinct;
        }

//        set<string> ss;
//        for(int i = 0;i < n - 1;i++){
//            string s1 = a.substr(0, i);
//            string s2 = a.substr(i + 2);
//            ss.insert(s1 + s2);
//        }

        cout << ans << '\n';
    }
}