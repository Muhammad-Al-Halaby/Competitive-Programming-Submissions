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

    int n;
    cin >> n;
    vector<pair<long double, int> > v;
    for(int i = 0;i < n;i++){
        long double x,y;
        cin >> x >> y;
        v.push_back(MP(atan2l(y,x), i + 1));
    }

    sort(v.begin(), v.end());

    v.push_back(v[0]);
    v[n].F += 8 * atanl(1);

    long double mini = 1e30, idx1, idx2;
    for(int i = n;i > 0;i--){
        if(v[i].F - v[i-1].F < mini){
            mini = v[i].F - v[i-1].F;
            idx1 = v[i].S;
            idx2 = v[i-1].S;
        }
    }

    cout << int(idx1) << " " << int(idx2);
}