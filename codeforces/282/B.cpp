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

const int N = 109, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;
    ll a = 0, g = 0;
    for(int i = 0;i < n;i++){
        int x, y;  cin >> x >> y;
        if(abs((a + x) - g) <= 500){
            cout << 'A';
            a += x;
        }else{
            cout << 'G';
            g += y;
        }
    }
}