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

const int N = 1e4 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        ll n, k;   cin >> n >> k;

        ll fn = n;

        ll x = n;
        for(ll i = 1;i * i <= n;i++){
            if(n % i == 0){
                if(i != 1)  x = min(i, x);
                if(n / i != 1)  x = min(n / i, x);
            }
        }

        fn += x;    k--;
        fn += k * 2;

        cout << fn << '\n';
    }
}