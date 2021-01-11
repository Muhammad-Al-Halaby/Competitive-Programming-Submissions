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


typedef long long ll;
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

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2) % 10;
    res *= res;
    if(p & 1)res *= b;
    return res % 10;
}

int main(){
    init();
    int b, k;
    cin >> b >> k;
    int ans = 0;
    for(int i = 0;i < k;i++){
        int x;
        cin >> x;
        ans += ((x % 10) * power(b, k-i-1)) % 10;
    }
    ans %= 10;
    if(ans % 2)
        cout << "odd";
    else
        cout << "even";
}