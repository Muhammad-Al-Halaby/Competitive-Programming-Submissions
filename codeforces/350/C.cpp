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

const int N = 100, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int freq[10] = {0};

vector<int> x[3];


void print(){
    int s = accumulate(freq, freq + 10, 0);
    if(!s || !freq[0])  cout << -1;
    else if(s == freq[0]) cout << 0;
    else for(int i = 9;~i;i--)  for(int j = 0;j < freq[i];j++)  cout << i;
    exit(0);
}


int main(){
    init();

    int n;  cin >> n;
    vector<pair<int, pii>> v;
    for(int i = 0;i < n;i++){
        int x, y;   cin >> x >> y;
        v.PB({abs(x) + abs(y),{x,y}});
    }

    sort(v.begin(), v.end());

    vector<pair<pii, char>> ans;
    for(int i = 0;i < n;i++){
        int x = v[i].S.F, y = v[i].S.S;
        if(x)   ans.push_back({{1, abs(x)}, ((x > 0) ? 'R' : 'L')});
        if(y)   ans.push_back({{1, abs(y)}, ((y > 0) ? 'U' : 'D')});
        ans.push_back({{2, 0}, '0'});
        if(y)   ans.push_back({{1, abs(y)}, ((y < 0) ? 'U' : 'D')});
        if(x)   ans.push_back({{1, abs(x)}, ((x < 0) ? 'R' : 'L')});
        ans.push_back({{3, 0}, '0'});
    }

    cout << ans.size() << '\n';
    for(auto a : ans)
        if(a.F.F > 1)   cout << a.F.F << '\n';
        else cout << a.F.F << " " << a.F.S << " " << a.S << '\n';
}
