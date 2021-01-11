#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

vector<ll> primes;

void sieve(){
    vector<bool> p(N, true);
    for(ll i = 2;i < N;i++){
        if(!p[i])    continue;
        primes.push_back(i);
        for(ll j = i * i;j < N;j+=i){
            p[j] = 0;
        }
    }
}

void go(int tc){
    ll n;  cin >> n;

    ll l = 0, r = primes.size() - 1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(primes[mid] * primes[mid] <= n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    int last = r;

    l = 0, r = primes.size() - 1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(primes[mid] <= n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r - last + 1 << '\n';
}

int main() {
    init();

//    freopen("in.in", "r", stdin);
//    freopenA("out.out", "w", stdout);


    sieve();
    int t = 1, tc = 1;
    cin >> t;
    while(t--)
        go(tc++);
}