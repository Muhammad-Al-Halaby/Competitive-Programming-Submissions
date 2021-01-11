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

const int N = 1e7 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


ll numDivisors[N];

void go(int tc){

    int n;  cin >> n;


    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j += i){
            numDivisors[j]++;
        }
    }

    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ans += i * numDivisors[i];
    }

    cout << ans;

}




int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;//  cin >> t;
    while(t--)  go(tc++);

}