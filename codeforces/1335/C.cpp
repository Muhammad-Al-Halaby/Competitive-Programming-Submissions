#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 50, M = 500, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int fr[n + 1] = {0}, a[n];
        set<int> s;
        for(int i = 0;i < n;i++){
            int x;  cin >> x;
            fr[x]++;
            s.insert(x);
        }

        int ans = 0;
        for(int i = 1;i <= n;i++){
            int f = fr[i];
            int lft = s.size() - (fr[i] > 0);
            ans = max(ans, min(f, lft));

            if(f > 1)
                ans = max(ans, min(f - 1, lft + 1));

        }

        cout << ans << '\n';

    }
}