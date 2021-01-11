#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int primes[(int)1e7];

void sieve(){
    primes[0] = primes[1] = 1;
    for(int i = 2;i < (int)1e7;i++){
        if(!primes[i]){
            for(ll j = (ll)i * i;j < (int)1e7;j+=i)
                primes[j] = 1;
        }
    }
}

int main(){
    init();
    int n, i = 0;
    sieve();
    cin >> n;
    while(n){
        if(!primes[i]){
            cout << i << " ";
            n--;
        }
        i++;
    }
}