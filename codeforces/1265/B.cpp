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

const int N = 2e5 + 10, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

bool in_range(ll x, ll l, ll r){
    return x >= l && x <= r;
}

int idx[N], ans[N];
int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        set<int> s;
        int l = 0, r = n - 1;
        for(int i = 0;i < n;i++){
            int x;  cin >> x;
//            s.insert(i);
            idx[x] = i;
        }


        for(int i = n;i > 0;i--){
            ans[i] = 0;
            int id = idx[i];
            int sz = r - l + 1;
            if(sz == i){
                ans[i] = 1;
            }
            if(id > idx[1] && in_range(id, l ,r)){
                r = id - 1;
//                while(id < n) s.erase(id++);
            }
            else if(id < idx[1] && in_range(id, l ,r)){
                l = id + 1;
//                while(id >= 0){
//                    s.erase(id--);
//                }
            }
        }

        for(int i = 1;i <= n;i++)
            cout << ans[i];
        cout << '\n';
    }


}