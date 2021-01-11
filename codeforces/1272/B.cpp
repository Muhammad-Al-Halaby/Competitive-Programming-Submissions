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

const int N = 5e3 + 5, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();

    int q;  cin >> q;
    while(q--){
        string s;   cin >> s;
        int u = 0, d = 0, l = 0, r = 0, n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == 'L')l++;
            else if(s[i] == 'R')r++;
            else if(s[i] == 'D')d++;
            else u++;
        }

        u = d = min(u, d);
        l = r = min(l, r);

        if(u > 1 && l == 0) u = d = 1;
        else if(l > 1 && u == 0)    l = r = 1;

        cout << (u + d + l + r) << '\n';
        for(int i = 0;i < u;i++)    cout << 'U';
        for(int i = 0;i < l;i++)    cout << 'L';
        for(int i = 0;i < d;i++)    cout << 'D';
        for(int i = 0;i < r;i++)    cout << 'R';

        cout << '\n';

    }

}





