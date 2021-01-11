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

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;   cin >> n >> m;

    vector<pii> f;
    int ans[n + 1], sorted[n + 1] = {0};
    for(int i = 0;i < m;i++){
        int t, l, r;    cin >> t >> l >> r;
        if(t){
            for(int i = l + 1;i <= r;i++)   sorted[i] = 1;
            continue;
        }
        f.push_back({l ,r});
    }

    ans[0] = 1e9 + 1;
    for(int i = 1;i <= n;i++)   ans[i] = 1e9;

    for(int i = 1;i <= n;i++){
        if(sorted[i])    continue;
        ans[i] = ans[i - 1] - 1;
    }

    for(auto p : f){
        int l = p.F, r = p.S;
        int ok = is_sorted(ans + l, ans + r + 1);
        if(ok)  return cout << "NO", 0;
     }

     cout << "YES\n";
     for(int i = 1;i <= n;i++)
        cout << ans[i] << " ";
}