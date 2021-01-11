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

const int N = 4e3+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    string a, b;    cin >> a >> b;
    int o = count(b.begin(), b.end(), '1');
    int z = count(b.begin(), b.end(), '0');

    int oo = count(a.begin(), a.begin() + b.size(), '1');
    int zz = count(a.begin(), a.begin() + b.size(), '0');


    int ans = 0;
    for(int i = 0;i < a.size();i++){
        int mismatched = b.size() - min(o, oo) - min(z, zz);
        if(mismatched % 2 == 0) ans++;
        if(i + b.size() >= a.size())    break;
        oo = oo - (a[i] == '1') + (a[i + b.size()] == '1');
        zz = zz - (a[i] == '0') + (a[i + b.size()] == '0');
    }

    cout << ans;
}