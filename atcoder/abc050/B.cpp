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

const int N = 2e5 + 9, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;




int main(){
    init();

    int n;  cin >> n;
    int t[n], sum = 0;
    for(int i = 0;i < n;i++)    cin >> t[i], sum += t[i];
    int m;  cin >> m;
    for(int i = 0;i < m;i++){
        int p, x;   cin >> p >> x;  p--;
        cout << sum - t[p] + x << '\n';
    }
}
