#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second


typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1e9+7;


ll lcm(ll a,ll b){
    return (a * b) / __gcd(a,b);
}

int div(ll b){
    int divisors = 0;
    for(ll i = 1;i * i <= b;i++)
        if(b % i == 0)divisors += 2;
    if(sqrt(b) == ll(sqrt(b)))divisors--;
    return divisors;
}
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    ll b;
    cin >> b;
    cout << div(b);
}