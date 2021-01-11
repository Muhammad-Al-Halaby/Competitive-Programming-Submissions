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

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, a, b, c, d;  cin >> n >> a >> b >> c >> d;


        int ok1 = 0, ok2 = 0;
        for(int i = (a - b); i <= (a + b);i++){
            if(n * i >= (c - d)) ok1 = 1;
            if(n * i <= (c + d)) ok2 = 1;
        }

        if(ok1 && ok2)
            cout << "Yes\n";
        else cout << "No\n";
    }


}