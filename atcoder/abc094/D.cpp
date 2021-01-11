#include <bits/stdc++.h>

using namespace std;

#define modulo ll (998244353)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];
    sort(a, a + n);

    int h = a[n - 1] / 2, d = 0;
    for(int i = 0;i < n - 1;i++){
        if(abs(h - a[i]) <= abs(h - a[d])){
            d = i;
        }
    }

    cout << a[n - 1] << " " << a[d];
}