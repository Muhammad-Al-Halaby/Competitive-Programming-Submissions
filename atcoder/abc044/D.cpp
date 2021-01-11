#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll sum(ll b, ll n){
    if(n < b)   return n;
    return sum(b, n / b) + (n % b);
}

int main(){
    init();

    ll n, s;    cin >> n >> s;
    if(n == s)  return cout << s + 1, 0;
//    if(n < s)   return cout << -1, 0;

    for(int i = 2;i <= 1e5;i++){
        ll sDigits = sum(i, n);
        if(sDigits == s)    return cout << i, 0;
    }


    /*
        q + pb = n
        q + p = s

        pb - p = n - s
        p(b - 1) = n - s
    */


    ll d = n - s, ans = llOO;
    for(ll i = 1;i * i <= d;i++){
        if(d % i == 0){
            if(sum(i + 1, n) == s)  ans = min(ans, i + 1);
            if(sum(d/i + 1, n) == s)  ans = min(ans, d/i + 1);
        }
    }

    cout << (ans == llOO ? -1 : ans);

}