#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int prime[M + 20];

void sieve(){
    prime[0] = prime[1] = 1;
    for(int i = 1;i <= M;i++){
        if(prime[i])
            continue;
        else{
            prime[i] = i;
            for(ll j = (ll)i*i;j<=M;j+=i){
                prime[j] = i;
            }
        }
    }
}

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    if(p & 1)res *= b;
    return res;
}

int cntP[M][32];

void factorize(int x){
    int p = prime[x];
    while(p > 1){
        int cnt = 0;
        while(x % p == 0){
            cnt++;
            x /= p;
        }
        cntP[p][cnt]++;
        cntP[p][0]--;
        p = prime[x];
    }
}

int main(){
    init();

    sieve();

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    for(int i = 2;i < M;i++){
        for(int j = 0;j < 32;j++)
            cntP[i][0] = n;
    }


    for(int i = 0;i < n;i++)    factorize(a[i]);

    ll gcd = 1;
    for(int i = 2;i < M;i++){
        if(cntP[i][0] > 1)  continue;

        int sum = cntP[i][0];

        for(int j = 1;j < 32;j++){
            if(cntP[i][j] > 1 || (cntP[i][j] && sum)){
                gcd *= power(i, j);
                break;
            }
            sum += cntP[i][j];
        }
    }

    cout << gcd;
}