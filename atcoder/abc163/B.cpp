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

const int N = 4e5 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int main(){
    init();

    int n, m;   cin >> n >> m;

    int sum = 0;
    for(int i = 0;i < m;i++){
        int x;  cin >> x;
        sum += x;
    }

    cout << max(n - sum, -1);

}