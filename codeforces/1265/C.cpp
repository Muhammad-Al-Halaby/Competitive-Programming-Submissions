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

const int N = 1e6 + 10, M = 1e5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

bool in_range(ll x, ll l, ll r){
    return x >= l && x <= r;
}

int fr[N];

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int p[n], last = n / 2 - 1;


        for(int i = 0;i < n;i++){
            cin >> p[i];
            fr[p[i]] = 0;
        }

        if(n < 4){
            cout << "0 0 0\n";
            continue;
        }

        int afterlast = last + 1;
        while(last >= 0 && p[afterlast] == p[last])  last--;

        set<int> ss;
        for(int i = 0;i <= last;i++){
            ss.insert(p[i]);
            fr[p[i]]++;
        }

        if(ss.size() < 3){
            cout << "0 0 0\n";
            continue;
        }

        vector<pii> v;
        for(auto pp : ss){
            v.push_back({pp, fr[pp]});
        }

        reverse(v.begin(), v.end());

        int bidx = v.size() - 2, sidx = 1;
        int g = v[0].S, s = 0, b = v.back().S;
        while(bidx > 0 && g >= b){
            b += v[bidx--].S;
        }
        if(bidx == 0){
            cout << "0 0 0\n";
            continue;
        }

        while(sidx <= bidx)  s += v[sidx++].S;

        if(s <= g){
            cout << "0 0 0\n";
            continue;
        }
        cout << g << " " << s << " " << b << '\n';

    }

}