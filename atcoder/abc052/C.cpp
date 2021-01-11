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

const int N = 1e3 + 9, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int primes[N];

void factorize(int n){
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            while(n % i == 0){
                primes[i]++;
                n /= i;
            }
        }
    }

    if(n != 1)  primes[n]++;
}

int main(){
    init();

    int n;  cin >> n;

    for(int i = 1;i <= n;i++)
        factorize(i);

    ll ans = 1;
    for(int i = 1;i <= n;i++){
        if(!primes[i])  continue;
        ans *= (primes[i] + 1);
        ans %= modulo;
    }

    cout << ans;
}