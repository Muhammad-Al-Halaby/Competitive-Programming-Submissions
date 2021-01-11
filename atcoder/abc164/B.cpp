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

const int N = 1e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();


    int a, b, c, d; cin >> a >> b >> c >> d;
    int p = 1;
    while(true){
        if(p){
            c -= b;
            if(c <= 0)  return cout << "Yes", 0;
        }
        else{
            a -= d;
            if(a <= 0)  return cout << "No", 0;
        }
        p ^= 1;
    }

}