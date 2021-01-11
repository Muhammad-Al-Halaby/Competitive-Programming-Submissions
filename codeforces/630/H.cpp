#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e3 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;   cin >> n;

    int two = 3, three = 1, five = 1;

    ll ans = 1;
    for(int i = 0;i < 5;i++){
        ans *= n * n;
        n--;
        while(ans % 2 == 0 && two) ans /= 2, two--;
        if(ans % 3 == 0 && three) ans /= 3, three--;
        if(ans % 5 == 0 && five) ans /= 5, five--;
    }

    cout << ans;
}