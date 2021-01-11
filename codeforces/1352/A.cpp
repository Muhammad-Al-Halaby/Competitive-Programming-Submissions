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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int p = 1;
        vector<int> v;
        while(n){
            int x = n % 10 * p;
            if(x)v.push_back(x);
            p *= 10;
            n /= 10;
        }

        cout << v.size() << '\n';
        for(auto vv : v)
            cout << vv << " ";
        cout << '\n';

    }

}
