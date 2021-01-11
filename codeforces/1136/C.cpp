#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();

    map<pair<int,int>, int> mp;

    int n,m;
    cin >> n >> m;
    loop(i,0,n){
        loop(j,0,m){
            int x;
            cin >> x;
            mp[MP(i+j,x)]++;
        }
    }

    loop(i,0,n){
        loop(j,0,m){
            int x;
            cin >> x;
            mp[MP(i+j,x)]--;
        }
    }

    for(auto x : mp){
        if(x.S != 0)
            return cout << "NO", 0;
    }

    cout << "YES";
}