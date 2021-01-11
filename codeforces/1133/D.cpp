#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
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

    int n,z = 0;
    cin >> n;
    int a[n],b[n];
    map<pii, int> mp;
    vector<pii> ds;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
        if(!a[i] && !b[i])z++;
    }

    for(int i = 0;i < n;i++){
        if(a[i])
        {
            int x = a[i],y = b[i];
            int gcd = __gcd(a[i],b[i]);
            x = x / gcd;
            y = -1.0 * (y / gcd);
            if(b[i] == 0)x = y = 0;
            ds.push_back(MP(x,y));
            mp[MP(x,y)]++;
        }
    }

    int ans = 0;
    for(int i = 0;i < ds.size();i++){
        ans = max(ans,mp[ds[i]]);
    }

    cout << ans + z;
}