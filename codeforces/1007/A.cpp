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

int main(){
    init();

    int n, mx = 0;

    cin >> n;

    map<int, int> mp;

    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
        mx = max(mx, mp[x]);
    }

    cout << n - mx;
}