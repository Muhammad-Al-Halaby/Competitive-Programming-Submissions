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
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

//int dx[] = {-1,1,0,0};
//int dy[] = {0,0,-1,1};

//int dx[] = {-1,1,0,0,1,-1,1,-1};
//int dy[] = {0,0,-1,1,1,-1,-1,1};

//    int powres[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    if(p & 1)res *= b;
    return res;
}

set<ll> factors;
set<ll> divisors;

void divide(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            divisors.insert(i);
            divisors.insert(n/i);

        }
    }
}

void factorize(ll n){
        for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            factors.insert(i);
            while(n % i == 0)n /= i;
        }
    }
    if(n != 1)factors.insert(n);
}

int n;
int pos[(int)1e5+1];
int h[(int)1e5+1];
map<pair<int, int>, int> dp;

int solve(int i, int maxleft){
    if(i >= n-1)
        return 0;

    if(dp.find(make_pair(i,maxleft)) != dp.end())
        return dp[make_pair(i,maxleft)];

    int & ans = dp[make_pair(i,maxleft)];

    //stay
    ans = solve(i+1, pos[i]+1);

    //left
    if(pos[i] - h[i] >= maxleft)
        ans += 1;

    //right
    if(pos[i] + h[i] < pos[i+1])
        ans = max(ans, 1 + solve(i+1, pos[i]+h[i]+1));

    return ans;
}

int main(){
    init();
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> pos[i] >> h[i];

    cout << ((n >= 2)?2:1) + solve(1,pos[0]+1);
}
