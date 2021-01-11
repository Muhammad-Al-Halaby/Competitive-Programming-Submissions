#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 25, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll sumOfDigits(ll n, ll b){
    if(n < b)   return n;
    return sumOfDigits(n / b, b) + (n % b);
}

int main(){
    init();

    ll sum = 0, a;  cin >> a;
    for(int i = 2;i < a;i++){
        sum += sumOfDigits(a, i);
    }

    ll cnt = a - 2;

    ll gcd = __gcd(sum, cnt);

    cout << sum/gcd << "/" << cnt/gcd;
}