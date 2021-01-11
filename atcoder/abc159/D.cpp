#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)

typedef long long ll;

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll freq[N];

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i], freq[a[i]]++;

    ll total = 0;
    for(int i = 1;i <= n;i++){
        total += freq[i] * (freq[i] - 1) / 2;
    }

    for(int i = 0;i < n;i++){
        total -= freq[a[i]] * (freq[a[i]] - 1) / 2;
        freq[a[i]]--;
        total += freq[a[i]] * (freq[a[i]] - 1) / 2;
        cout << total << '\n';
        total -= freq[a[i]] * (freq[a[i]] - 1) / 2;
        freq[a[i]]++;
        total += freq[a[i]] * (freq[a[i]] - 1) / 2;
    }
}