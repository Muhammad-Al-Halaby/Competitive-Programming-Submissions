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

const int N = 1e5+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();


    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        vector<pii> v;
        for(int i  = 0;i < n;i++){
            int x,y;    cin >> x >> y;
            v.PB({x,y});
        }

        v.push_back({0, 0});
        sort(v.begin(), v.end());

        string s  = "";
        int ok = 1;
        for(int i = 1;i < n + 1;i++){
            if(v[i].S < v[i - 1].S){
                ok = 0;
                break;
            }

            int dx = v[i].F - v[i-1].F;
            while(dx--) s += 'R';
            int dy = v[i].S - v[i-1].S;
            while(dy--) s += 'U';
        }

        if(ok){
            cout << "YES\n" << s << '\n';
        }
        else    cout << "NO\n";
    }




}