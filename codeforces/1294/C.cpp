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



set<ll> divisors;

void divide(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    if(divisors.empty())    divisors.insert(n);
}



int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;   divide(n);
        vector<int> divs(divisors.begin(), divisors.end());
        int a = divs[0];
        divisors.clear();
        divide(divs.back());
        vector<int> nxt(divisors.begin(), divisors.end());
        int ok = 0;
        for(int i = 0;2*i < nxt.size() - (nxt.size() & 1);i++){
            if(nxt[i] != a){
                cout << "YES\n" << a << " " << nxt[i] << " " << nxt[nxt.size()-i-1] << '\n';
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "NO\n";
        divisors.clear();
    }
}