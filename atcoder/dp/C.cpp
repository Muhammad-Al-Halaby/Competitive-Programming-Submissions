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

int Max = 1e7 + 5;
int prime[(int)1e7+7];

void sieve(){
    prime[0] = prime[1] = 1;
    for(ll i = 1;i<=Max;i++){
        if(prime[i])
            continue;
        else{
            for(ll j = i*i;j<=Max;j+=i)
                prime[j] = 1;
        }
    }
}

int main(){
    init();
    int n;
    cin >> n;

    int p = 0, dp[2][3];
    memset(dp, 0, sizeof dp);

    for(int i = 0;i < n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        p ^= 1;

        dp[p][0] = a + max(dp[p^1][1],dp[p^1][2]);
        dp[p][1] = b + max(dp[p^1][0],dp[p^1][2]);
        dp[p][2] = c + max(dp[p^1][0],dp[p^1][1]);

    }

    cout << max(dp[p][0],max(dp[p][1],dp[p][2]));
}
