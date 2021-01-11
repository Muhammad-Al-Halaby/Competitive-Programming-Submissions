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
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int ok[N];
int main(){
    init();

    int n, k;   cin >> n >> k;
    for(int i = 0;i < k;i++){
        int d;  cin >> d;
        while(d--){
            int x;  cin >> x;
            ok[x]++;
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;i++)   ans += ok[i] == 0;

    cout << ans;
}


